using UnityEngine;
using System.Collections.Generic;
using System.Collections;

public class VehicleController : MonoBehaviour
{
    [Header("1. Managers")]
    public VehicleInputManager inputManager;
    public FMUManager fmuManager;

    [Header("2. Simulation Settings")]
    // [NEW] 스폰 포인트 (빈 오브젝트를 만들어서 할당)
    public Transform spawnPoint;

    [Header("3. Vehicle FMU Inputs")]
    [FMUVariable(true)] public string var_Steer_In;
    [FMUVariable(true)] public string var_Throttle_In;
    [FMUVariable(true)] public string var_Brake_In;
    [FMUVariable(true)] public string var_Gear_In;

    [Header("4. Vehicle FMU Outputs")]
    [FMUVariable] public string out_ChassisPos_X;
    [FMUVariable] public string out_ChassisPos_Y;
    [FMUVariable] public string out_ChassisPos_Z;

    [FMUVariable] public string out_ChassisRot_X;
    [FMUVariable] public string out_ChassisRot_Y;
    [FMUVariable] public string out_ChassisRot_Z;
    [FMUVariable] public string out_ChassisRot_W;

    [Header("5. Toe & Wheels")]
    [FMUVariable] public string out_Toe_Left;
    [FMUVariable] public string out_Toe_Right;
    public List<WheelData> wheels;
    public Vector3 wheelRootCorrection = new Vector3(-90, 0, 0);
    public Vector3 wheelVisualCorrection = new Vector3(0, 0, 0);
    // 내부 계산용 변수
    private Vector3 _spawnPos = Vector3.zero;
    private Quaternion _spawnRot = Quaternion.identity;
    private bool _isRespawning = false;
    public LayerMask mapLayer;

    private void Awake()
    {
        // 인스펙터 설정과 상관없이 Default, Road, Map 레이어를 충돌 감지 대상에 자동 포함
        int defaultLayer = LayerMask.NameToLayer("Default");
        int roadLayer = LayerMask.NameToLayer("Road");
        int mapLayerIndex = LayerMask.NameToLayer("Map");

        if (defaultLayer != -1) mapLayer |= (1 << defaultLayer);
        if (roadLayer != -1) mapLayer |= (1 << roadLayer);
        if (mapLayerIndex != -1) mapLayer |= (1 << mapLayerIndex);
    }
    void Start()
    {
        // 시작할 때 스폰 포인트의 위치/회전을 기억해둡니다.
        if (spawnPoint != null)
        {
            //_spawnPos = spawnPoint.position;
            //_spawnRot = spawnPoint.rotation;
            ResetVehicle(spawnPoint.position, spawnPoint.rotation);
        }
        else
        {
            // 스폰 포인트가 없으면 현재 차의 위치를 원점으로 삼음
            //_spawnPos = transform.position;
            //_spawnRot = transform.rotation;
            ResetVehicle(transform.position, transform.rotation);
            Debug.LogWarning("Spawn Point가 없습니다! 현재 위치를 원점으로 사용합니다.");
        }

        if(inputManager != null)
        {
            inputManager.OnResetTriggered += () =>
            {
                if (spawnPoint != null)
                {
                    ResetVehicle(spawnPoint.position, spawnPoint.rotation);
                }
                else
                {
                    ResetVehicle(Vector3.zero,Quaternion.identity);
                }
            };
        }


    }

    void FixedUpdate()
    {
        if (fmuManager == null || inputManager == null) return;

        // --- [STEP 1] Input (기존 동일) ---
        float targetSteer = inputManager.Steering * (450.0f * Mathf.Deg2Rad); // 임시 계수
        if (!string.IsNullOrEmpty(var_Steer_In)) fmuManager.SetValue(var_Steer_In, targetSteer);
        if (!string.IsNullOrEmpty(var_Throttle_In)) fmuManager.SetValue(var_Throttle_In, inputManager.Accel);
        if (!string.IsNullOrEmpty(var_Brake_In)) fmuManager.SetValue(var_Brake_In, inputManager.Brake);
        if (!string.IsNullOrEmpty(var_Gear_In)) fmuManager.SetValue(var_Gear_In, (int)inputManager.Gear);


        foreach (var w in wheels)
        {
            if (w.sensor != null) w.sensor.CalculateGroundForces();

            // [원리]: FMU 모델 내부의 바퀴 패치 높이(gz) 조절을 위해,
            // 침투량이 아닌 '스폰 위치 대비 실제 지면의 상대적 Y 높이 (hitPointY - _spawnPos.y)'를 FMU에 전달합니다.
            if (!string.IsNullOrEmpty(w.var_GroundDist_In))
            {
                float relativeGroundY = w.sensor.isGrounded ? (w.sensor.hitPointY - _spawnPos.y) : 0f;
                fmuManager.SetValue(w.var_GroundDist_In, relativeGroundY);
            }
        }

        // --- [STEP 2] Simulation ---
        fmuManager.DoStep();

        // --- [STEP 3] Output (좌표 변환 추가!) ---
        ApplyChassisWithSpawn();
        ApplyWheels();
    }

    // ★ 핵심: 스폰 포인트 기준으로 좌표 변환
    void ApplyChassisWithSpawn()
    {
        // 1. FMU에서 계산된 로컬 좌표 (0,0,0 기준) 가져오기
        float cx = (float)fmuManager.GetValue(out_ChassisPos_X);
        float cy = (float)fmuManager.GetValue(out_ChassisPos_Y);
        float cz = (float)fmuManager.GetValue(out_ChassisPos_Z);
        //Vector3 fmuPos = new Vector3(-cy, cz, cx); // 좌표계(Z-up) 확인 필요시 (cx, cz, cy)
        Vector3 fmuPos = new Vector3(cx, cy, cz);

        // 2. FMU 회전 가져오기
        float qx = (float)fmuManager.GetValue(out_ChassisRot_X);
        float qy = (float)fmuManager.GetValue(out_ChassisRot_Y);
        float qz = (float)fmuManager.GetValue(out_ChassisRot_Z);
        float qw = (float)fmuManager.GetValue(out_ChassisRot_W);

        Quaternion fmuRot = new Quaternion(qx, qy, qz, qw);

        // 3. [좌표 변환] 유니티 월드 좌표 = 스폰위치 + (스폰회전 * FMU이동량)
        // 이렇게 하면 스폰 포인트가 90도 꺾여 있어도, 차가 그 방향 기준으로 앞으로 갑니다.
        //transform.position = _spawnPos + (_spawnRot * fmuPos);
        transform.position = _spawnPos +(_spawnRot * fmuPos);

        // 4. [회전 변환] 유니티 월드 회전 = 스폰회전 * FMU회전
        transform.rotation = _spawnRot * fmuRot;
    }

    void ApplyWheels()
    {
        // 바퀴는 Chassis(부모)가 이미 이동했으므로, 
        // localPosition을 쓰면 Chassis를 따라 자연스럽게 이동합니다.
        // (기존 코드 유지)

        float toeL = (float)fmuManager.GetValue(out_Toe_Left);
        float toeR = (float)fmuManager.GetValue(out_Toe_Right);

        foreach (var w in wheels)
        {
            // 위치 (Chassis 기준 상대 좌표라고 가정)
            if (!string.IsNullOrEmpty(w.var_WheelPos_X))
            {
                float wx = (float)fmuManager.GetValue(w.var_WheelPos_X);
                float wy = (float)fmuManager.GetValue(w.var_WheelPos_Y);
                float wz = (float)fmuManager.GetValue(w.var_WheelPos_Z);
                w.wheelRoot.localPosition = new Vector3(wx, wy, wz);
            }

            // 회전 (Steering 및 Quaternion 회전)
            if (!string.IsNullOrEmpty(w.var_WheelRot_X))
            {
                float rx = (float)fmuManager.GetValue(w.var_WheelRot_X);
                float ry = (float)fmuManager.GetValue(w.var_WheelRot_Y);
                float rz = (float)fmuManager.GetValue(w.var_WheelRot_Z);
                float rw = (float)fmuManager.GetValue(w.var_WheelRot_W);
                w.wheelRoot.localRotation = new Quaternion(rx, ry, rz, rw);
            }
            else if (w.id == "FL" || w.id == "FR")
            {
                Quaternion toeRot = Quaternion.identity;
                if (w.id == "FL") toeRot = Quaternion.Euler(0, toeL * Mathf.Rad2Deg, 0);
                else if (w.id == "FR") toeRot = Quaternion.Euler(0, toeR * Mathf.Rad2Deg, 0);
                w.wheelRoot.localRotation = toeRot;
            }

            // 스핀 (Rolling)
            if (!string.IsNullOrEmpty(w.var_WheelSpin_Out))
            {
                float spin = (float)fmuManager.GetValue(w.var_WheelSpin_Out);
                w.wheelVisual.localRotation = Quaternion.Euler(spin * Mathf.Rad2Deg, 0, 0);
            }
        }
    }

    public void ResetVehicle(Vector3 targetAnchorPos, Quaternion targetAnchorRot)
    {
        _spawnPos = targetAnchorPos;
        _spawnRot = targetAnchorRot;

        if(fmuManager != null)
        {
            fmuManager.ResetFMU();
        }
        transform.position = _spawnPos;
        transform.rotation = _spawnRot;
        Debug.Log($"Spawned at {_spawnPos}");
    }

    IEnumerator CollisionRespawnRoutine()
    {
        _isRespawning = true;
        if (inputManager != null) inputManager.SetInputActive(false);
        Vector3 forwardVec = transform.forward;
        forwardVec.y = 0;
        forwardVec.Normalize();
        Vector3 backPos = transform.position - (forwardVec * 10.0f);
        // [수정]: 맵마다 지면 높이 Y가 다르므로 Y=0으로 강제 고정하던 코드를 주석 처리합니다.
        // // backPos.y = 0;
        Quaternion flatRotation = Quaternion.LookRotation(forwardVec);
        ResetVehicle(backPos, flatRotation);
        yield return new WaitForSeconds(1f);
        if (UIManager.Instance != null)
        {
            // 코루틴은 Instance 함수를 빌려서 실행
            UIManager.Instance.EndCollisionEffect();
        }
        if (inputManager != null) inputManager.SetInputActive(true);
        _isRespawning = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (_isRespawning) return;

        // 부딪힌 놈(other)의 레이어가 Map인지 확인
        // (비트 연산: 내 mapLayer에 포함된 놈인가?)
        if ((mapLayer.value & (1 << other.gameObject.layer)) != 0)
        {
            if (UIManager.Instance != null)
            {
                UIManager.Instance.StartCollisionEffect();
            }
            Debug.Log($"{other.gameObject.name}에 충돌");
            StartCoroutine(CollisionRespawnRoutine());
        }
    }
}
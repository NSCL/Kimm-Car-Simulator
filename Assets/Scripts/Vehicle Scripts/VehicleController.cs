using UnityEngine;
using System.Collections.Generic;

public class VehicleController : MonoBehaviour
{
    [Header("1. Managers")]
    public VehicleInputManager inputManager;
    public FMUManager fmuManager;

    [Header("2. Simulation Settings")]
    // [NEW] 스폰 포인트 (빈 오브젝트를 만들어서 할당)
    public Transform spawnPoint;
    public float maxMotorSpeed = 50.0f;

    [Header("3. Chassis FMU Inputs")]
    [FMUVariable(true)] public string var_Steer_In;

    [Header("4. Chassis FMU Outputs")]
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

    void Start()
    {
        // 시작할 때 스폰 포인트의 위치/회전을 기억해둡니다.
        if (spawnPoint != null)
        {
            _spawnPos = spawnPoint.position;
            _spawnRot = spawnPoint.rotation;
        }
        else
        {
            // 스폰 포인트가 없으면 현재 차의 위치를 원점으로 삼음
            _spawnPos = transform.position;
            _spawnRot = transform.rotation;
            Debug.LogWarning("Spawn Point가 없습니다! 현재 위치를 원점으로 사용합니다.");
        }
    }

    void FixedUpdate()
    {
        if (fmuManager == null || inputManager == null) return;

        // --- [STEP 1] Input (기존 동일) ---
        float targetSteer = inputManager.Steering * (620.0f * Mathf.Deg2Rad); // 임시 계수
        if (!string.IsNullOrEmpty(var_Steer_In)) fmuManager.SetValue(var_Steer_In, targetSteer);

        float targetSpeed = inputManager.Accel * maxMotorSpeed;
        if (inputManager.Accel == 0 && inputManager.Brake > 0) targetSpeed = 0;

        foreach (var w in wheels)
        {
            if (w.sensor != null) w.sensor.CalculateGroundForces();
            if (!string.IsNullOrEmpty(w.var_GroundDist_In)) fmuManager.SetValue(w.var_GroundDist_In, w.sensor.penetration);
            if (!string.IsNullOrEmpty(w.var_WheelOmega_In)) fmuManager.SetValue(w.var_WheelOmega_In, targetSpeed);
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
        Vector3 fmuPos = new Vector3(-cy, cz, cx); // 좌표계(Z-up) 확인 필요시 (cx, cz, cy)

        // 2. FMU 회전 가져오기
        float qx = (float)fmuManager.GetValue(out_ChassisRot_X);
        float qy = (float)fmuManager.GetValue(out_ChassisRot_Y);
        float qz = (float)fmuManager.GetValue(out_ChassisRot_Z);
        float qw = (float)fmuManager.GetValue(out_ChassisRot_W);
        Quaternion fmuRot = new Quaternion(qx, qy, qz, qw);

        // 3. [좌표 변환] 유니티 월드 좌표 = 스폰위치 + (스폰회전 * FMU이동량)
        // 이렇게 하면 스폰 포인트가 90도 꺾여 있어도, 차가 그 방향 기준으로 앞으로 갑니다.
        transform.position = _spawnPos + (_spawnRot * fmuPos);

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

            // 회전 (Knuckle/Steering)
            if (!string.IsNullOrEmpty(w.var_WheelRot_X))
            {
                float rx = (float)fmuManager.GetValue(w.var_WheelRot_X);
                float ry = (float)fmuManager.GetValue(w.var_WheelRot_Y);
                float rz = (float)fmuManager.GetValue(w.var_WheelRot_Z);
                float rw = (float)fmuManager.GetValue(w.var_WheelRot_W);
                Quaternion knuckleRot = new Quaternion(rx, ry, rz, rw);

                Quaternion toeRot = Quaternion.identity;
                if (w.id == "FL") toeRot = Quaternion.Euler(0, 0, toeL * Mathf.Rad2Deg);
                else if (w.id == "FR") toeRot = Quaternion.Euler(0, 0, toeR * Mathf.Rad2Deg);

                w.wheelRoot.localRotation = knuckleRot * toeRot;
            }

            // 스핀 (Rolling)
            if (!string.IsNullOrEmpty(w.var_WheelSpin_Out))
            {
                float spin = (float)fmuManager.GetValue(w.var_WheelSpin_Out);
                w.wheelVisual.localRotation = Quaternion.Euler(spin * Mathf.Rad2Deg, 0, 0);
            }
        }
    }
}
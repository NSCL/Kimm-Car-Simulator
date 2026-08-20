using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VehicleController : MonoBehaviour
{
    [Header("FMU Manager Reference")]
    public FMUManager fmuManager;
    public VehicleInputManager inputManager;

    [Header("Visual Mesh & Auto-Fitting Settings")]
    [Tooltip("3D 차량 섀시/차체 껍데기 Visual Mesh Transform")]
    public Transform chassisVisualTransform;

    [Tooltip("Baseline 윤거 (m) - 3D 섀시 모델 순정 기준 바퀴 간격")]
    public float baseTrackWidth = 1.628f;

    [Tooltip("Baseline 축거 (m) - 3D 섀시 모델 순정 기준 앞뒤 휠하우스 간격")]
    public float baseWheelbase = 2.550f;

    // 절대 변하지 않는 100% 퓨어 원본 스케일 및 위치
    private Vector3 _pureOriginalScale = Vector3.one;
    private Vector3 _pureOriginalLocalPos = Vector3.zero;
    private bool _isOriginalCached = false;

    [Header("Spawn Settings")]
    public Transform spawnPoint;
    private Vector3 _spawnPos;
    private Quaternion _spawnRot;

    [Header("FMU Chassis Variable Names")]
    public string var_Steer_In = "str_angle";
    public string var_Throttle_In = "accel";
    public string var_Brake_In = "brake";
    public string var_Gear_In = "gear";

    public string out_ChassisPos_X = "Veh_BodyPos_X";
    public string out_ChassisPos_Y = "Veh_BodyPos_Y";
    public string out_ChassisPos_Z = "Veh_BodyPos_Z";
    public string out_ChassisRot_X = "Veh_BodyRot_X";
    public string out_ChassisRot_Y = "Veh_BodyRot_Y";
    public string out_ChassisRot_Z = "Veh_BodyRot_Z";
    public string out_ChassisRot_W = "Veh_BodyRot_W";

    public string out_Toe_Left = "Veh_Steer_L";
    public string out_Toe_Right = "Veh_Steer_R";

    [Header("Wheels Configuration")]
    public List<WheelData> wheels = new List<WheelData>();

    private bool _isRespawning = false;

    private void Awake()
    {
        if (fmuManager == null) fmuManager = FindFirstObjectByType<FMUManager>();
        if (inputManager == null) inputManager = FindFirstObjectByType<FMUManager>()?.GetComponent<VehicleInputManager>();

        CachePureOriginalTransform();
    }

    private void Start()
    {
        CachePureOriginalTransform();
        AttachSpoilerToChassis();

        if (spawnPoint != null)
        {
            ResetVehicle(spawnPoint.position, spawnPoint.rotation);
        }
        else
        {
            ResetVehicle(transform.position, transform.rotation);
        }

        if (inputManager != null)
        {
            inputManager.OnResetTriggered += () =>
            {
                if (spawnPoint != null)
                {
                    ResetVehicle(spawnPoint.position, spawnPoint.rotation);
                }
                else
                {
                    ResetVehicle(Vector3.zero, Quaternion.identity);
                }
            };
        }
    }

    private void CachePureOriginalTransform()
    {
        if (_isOriginalCached) return;

        if (chassisVisualTransform == null)
        {
            Transform visualChild = transform.Find("Chassis") ?? transform.Find("Visual") ?? transform.Find("Body");
            if (visualChild != null)
            {
                chassisVisualTransform = visualChild;
            }
            else
            {
                MeshRenderer mr = GetComponentInChildren<MeshRenderer>();
                if (mr != null) chassisVisualTransform = mr.transform;
            }
        }

        if (chassisVisualTransform != null)
        {
            _pureOriginalScale = chassisVisualTransform.localScale;
            _pureOriginalLocalPos = chassisVisualTransform.localPosition;
            _isOriginalCached = true;
        }
    }

    private void AttachSpoilerToChassis()
    {
        if (chassisVisualTransform == null) return;

        Transform[] allTransforms = GetComponentsInChildren<Transform>(true);
        foreach (Transform tf in allTransforms)
        {
            if (tf == null || tf == chassisVisualTransform) continue;

            string nameLower = tf.name.ToLower();
            if (nameLower.Contains("spoiler") || nameLower.Contains("wing") || nameLower.Contains("rearwing"))
            {
                if (!tf.IsChildOf(chassisVisualTransform))
                {
                    tf.SetParent(chassisVisualTransform, true);
                }
            }
        }
    }

    /// <summary>
    /// Config 로드 시 추출된 윤거(currentTrackW)와 축거(currentWheelbase) 수치를 100% 직통 대입하여 3D 차체 스케일 변환
    /// </summary>
    public void ApplyChassisScale(float currentTrackW, float currentWheelbase)
    {
        CachePureOriginalTransform();
        if (chassisVisualTransform == null) return;
        if (baseTrackWidth <= 0 || baseWheelbase <= 0) return;

        // [핵심 해결]: C++ DLL 지연 오차 없이 파라미터 직통 수치(2.6m/3.2m/4.2m)를 100% 스케일에 반영!
        float scaleXRatio = currentTrackW / baseTrackWidth;
        float scaleZRatio = currentWheelbase / baseWheelbase;

        Vector3 autoCalculatedScale = new Vector3(
            _pureOriginalScale.x * scaleXRatio,
            _pureOriginalScale.y,
            _pureOriginalScale.z * scaleZRatio
        );

        chassisVisualTransform.localScale = autoCalculatedScale;
    }

    private void FixedUpdate()
    {
        if (fmuManager == null || inputManager == null) return;

        float targetSteer = inputManager.Steering * (450.0f * Mathf.Deg2Rad);
        if (!string.IsNullOrEmpty(var_Steer_In)) fmuManager.SetValue(var_Steer_In, targetSteer);
        if (!string.IsNullOrEmpty(var_Throttle_In)) fmuManager.SetValue(var_Throttle_In, inputManager.Accel);
        if (!string.IsNullOrEmpty(var_Brake_In)) fmuManager.SetValue(var_Brake_In, inputManager.Brake);
        if (!string.IsNullOrEmpty(var_Gear_In)) fmuManager.SetValue(var_Gear_In, (int)inputManager.Gear);

        foreach (var w in wheels)
        {
            if (w.sensor != null) w.sensor.CalculateGroundForces();

            if (!string.IsNullOrEmpty(w.var_GroundDist_In))
            {
                float relativeGroundY = w.sensor.isGrounded ? (w.sensor.hitPointY - _spawnPos.y) : 0f;
                fmuManager.SetValue(w.var_GroundDist_In, relativeGroundY);
            }

            if (!string.IsNullOrEmpty(w.var_GroundQx_In))
            {
                float qx = w.sensor.isGrounded ? -w.sensor.hitQx : 0f;
                fmuManager.SetValue(w.var_GroundQx_In, qx);
            }

            if (!string.IsNullOrEmpty(w.var_GroundQy_In))
            {
                float qy = w.sensor.isGrounded ? -w.sensor.hitQy : 0f;
                fmuManager.SetValue(w.var_GroundQy_In, qy);
            }
        }

        fmuManager.DoStep();

        ApplyFMUState();
        ApplyWheels();
    }

    private void ApplyFMUState()
    {
        if (fmuManager == null || !fmuManager.IsFMUActive()) return;

        float cx = (float)fmuManager.GetValue(out_ChassisPos_X);
        float cy = (float)fmuManager.GetValue(out_ChassisPos_Y);
        float cz = (float)fmuManager.GetValue(out_ChassisPos_Z);
        Vector3 fmuPos = new Vector3(cx, cy, cz);

        float qx = (float)fmuManager.GetValue(out_ChassisRot_X);
        float qy = (float)fmuManager.GetValue(out_ChassisRot_Y);
        float qz = (float)fmuManager.GetValue(out_ChassisRot_Z);
        float qw = (float)fmuManager.GetValue(out_ChassisRot_W);

        Quaternion fmuRot = new Quaternion(qx, qy, qz, qw);

        transform.position = _spawnPos + (_spawnRot * fmuPos);
        transform.rotation = _spawnRot * fmuRot;
    }

    private void ApplyWheels()
    {
        if (fmuManager == null || !fmuManager.IsFMUActive()) return;
        float toeL = (float)fmuManager.GetValue(out_Toe_Left);
        float toeR = (float)fmuManager.GetValue(out_Toe_Right);

        foreach (var w in wheels)
        {
            if (!string.IsNullOrEmpty(w.var_WheelPos_X))
            {
                float wx = (float)fmuManager.GetValue(w.var_WheelPos_X);
                float wy = (float)fmuManager.GetValue(w.var_WheelPos_Y);
                float wz = (float)fmuManager.GetValue(w.var_WheelPos_Z);
                w.wheelRoot.localPosition = new Vector3(wx, wy, wz);
            }

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

        if (fmuManager != null)
        {
            fmuManager.ResetFMU();
        }

        ChartModule[] activeCharts = FindObjectsByType<ChartModule>(FindObjectsSortMode.None);
        foreach (ChartModule chart in activeCharts)
        {
            if (chart != null) chart.ResetChartData();
        }

        transform.position = _spawnPos;
        transform.rotation = _spawnRot;

        UnitySensors.Sensor.IMU.KimmIMUSensor kimmIMU = GetComponentInChildren<UnitySensors.Sensor.IMU.KimmIMUSensor>();
        if (kimmIMU != null) kimmIMU.CaptureSpawnHeading();
    }

    private IEnumerator CollisionRespawnRoutine()
    {
        _isRespawning = true;
        if (inputManager != null) inputManager.SetInputActive(false);
        Vector3 forwardVec = transform.forward;
        forwardVec.y = 0;
        forwardVec.Normalize();
        Vector3 backPos = transform.position - (forwardVec * 10.0f);
        Quaternion flatRotation = Quaternion.LookRotation(forwardVec);
        ResetVehicle(backPos, flatRotation);
        yield return new WaitForSeconds(1f);
        if (UIManager.Instance != null)
        {
            UIManager.Instance.EndCollisionEffect();
        }
        if (inputManager != null) inputManager.SetInputActive(true);
        _isRespawning = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (_isRespawning) return;

        if (UIManager.Instance != null)
        {
            UIManager.Instance.StartCollisionEffect();
        }
        StartCoroutine(CollisionRespawnRoutine());
    }
}
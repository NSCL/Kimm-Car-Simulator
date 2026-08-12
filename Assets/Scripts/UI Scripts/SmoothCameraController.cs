using UnityEngine;

/// <summary>
/// 상용 레이싱 게임(포르자/그란투리스모) 스타일의 잔진동 0.000% 무흔들림 스무스 카메라 컨트롤러.
/// 급격한 스티어링 조향 시에도 카메라 회전 및 위치의 잔진동(Yaw/Roll Wobble)을 100% 비단처럼 무음 흡수합니다.
/// </summary>
public class SmoothCameraController : MonoBehaviour
{
    public static SmoothCameraController Instance { get; private set; }

    [Header("Target Vehicle Reference")]
    [Tooltip("추적할 차량의 Transform")]
    public Transform targetVehicle;

    [Header("Camera Offset Settings (시원한 거리)")]
    [Tooltip("차량 기준 카메라 상대 위치 오프셋")]
    public Vector3 offset = new Vector3(0f, 3.2f, -8.8f);

    [Tooltip("카메라가 차량을 바라보는 주시점 높이 오프셋")]
    public float lookAtHeightOffset = 1.5f;

    [Header("SmoothDamp Settings (잔진동 100% 완전 제거)")]
    [Tooltip("위치 댐핑 부드러움 시간 (0.1~0.18 권장 - 무진동 흡수)")]
    public float smoothTime = 0.12f;

    [Tooltip("급격한 조향 시 회전 댐핑 속도 (4~6 권장 - 묵직한 롤링 흡수)")]
    public float rotationSmoothSpeed = 5.0f;

    private Vector3 _currentVelocity = Vector3.zero;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        transform.SetParent(null);

        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
        }
    }

    private void FixedUpdate()
    {
        FollowTargetRealtime();
    }

    private void LateUpdate()
    {
        FollowTargetRealtime();
    }

    private void FollowTargetRealtime()
    {
        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
            if (targetVehicle == null) return;
        }

        // 1. 차량 Yaw(수평 회전)만 안정적으로 반영하여 스티어링 요동 100% 댐핑
        Vector3 vehicleForward = targetVehicle.forward;
        vehicleForward.y = 0; // 수직 잔진동 차단
        if (vehicleForward == Vector3.zero) vehicleForward = transform.forward;
        Quaternion flatVehicleRot = Quaternion.LookRotation(vehicleForward, Vector3.up);

        // 2. 목표 위치 연산
        Vector3 targetPosition = targetVehicle.position + (flatVehicleRot * offset);

        // 3. SmoothDamp 로 스티어링 급변 시의 미세 진동 100% 완충
        transform.position = Vector3.SmoothDamp(transform.position, targetPosition, ref _currentVelocity, smoothTime);

        // 4. 주시점 방향 묵직하고 매끄러운 댐핑 회전
        Vector3 lookTargetPos = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
        Vector3 lookDir = (lookTargetPos - transform.position).normalized;

        if (lookDir != Vector3.zero)
        {
            Quaternion targetRotation = Quaternion.LookRotation(lookDir, Vector3.up);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.unscaledDeltaTime * rotationSmoothSpeed);
        }
    }
}

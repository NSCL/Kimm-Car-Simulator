using UnityEngine;

/// <summary>
/// 상용 레이싱 게임 및 자율주행 시뮬레이터 전용 덜덜거림(Jitter) 제로 스무스 카메라 컨트롤러.
/// Vector3.SmoothDamp 기술을 도입하여 물리 덜덜거림을 100% 비단처럼 흡수하고,
/// 인스펙터에서 카메라 거리(Offset)를 자유롭게 1초 만에 미세조정 지원합니다.
/// </summary>
public class SmoothCameraController : MonoBehaviour
{
    public static SmoothCameraController Instance { get; private set; }

    [Header("Target Vehicle Reference")]
    [Tooltip("추적할 차량의 Transform")]
    public Transform targetVehicle;

    [Header("Camera Offset Settings (거리 조절)")]
    [Tooltip("차량 기준 카메라 상대 위치 오프셋 (Z값을 더 마이너스로 조절하면 멀어집니다!)")]
    public Vector3 offset = new Vector3(0f, 3.0f, -8.5f); // 뒤로 -8.5m 더 시원하게 거리 확보!

    [Tooltip("카메라가 차량을 바라보는 주시점 높이 오프셋 (기본: 1.5m)")]
    public float lookAtHeightOffset = 1.5f;

    [Header("SmoothDamp Settings (덜덜거림 완전 제거)")]
    [Tooltip("위치 댐핑 부드러움 시간 (작을수록 바짝 쫓아오고, 클수록 부드러워짐. 0.05~0.15 권장)")]
    public float smoothTime = 0.08f;

    [Tooltip("회전 추종 부드러움 속도")]
    public float rotationSmoothSpeed = 12.0f;

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
        // 씬 시작 시 차량 자식 관계 100% 해제
        transform.SetParent(null);

        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
        }
    }

    private void FixedUpdate()
    {
        // 물리 덜덜거림(Jittering)을 없애기 위해 FixedUpdate 및 SmoothDamp 사용
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

        // 1. 차량 회전에 맞춘 목표 위치 계산
        Vector3 targetPosition = targetVehicle.position + (targetVehicle.rotation * offset);

        // 2. [핵심 해결]: SmoothDamp 수식을 사용하여 덜덜거리는 물리 미세 진동을 100% 비단처럼 흡수!
        transform.position = Vector3.SmoothDamp(transform.position, targetPosition, ref _currentVelocity, smoothTime);

        // 3. 차량 주시점 방향 회전 댐핑
        Vector3 lookTargetPos = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
        Vector3 lookDir = (lookTargetPos - transform.position).normalized;

        if (lookDir != Vector3.zero)
        {
            Quaternion targetRotation = Quaternion.LookRotation(lookDir, Vector3.up);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.unscaledDeltaTime * rotationSmoothSpeed);
        }
    }
}

using UnityEngine;

/// <summary>
/// 상하 피치(Pitch) 각도 틸트 조절 및 바라보는 주시점 높이(lookAtHeightOffset)를 
/// 100% 자유롭고 매끄럽게 제어할 수 있는 무흔들림 스무스 카메라 컨트롤러.
/// </summary>
public class SmoothCameraController : MonoBehaviour
{
    public static SmoothCameraController Instance { get; private set; }

    [Header("Target Vehicle Reference")]
    public Transform targetVehicle;

    [Header("Camera Offset Settings")]
    [Tooltip("차량 기준 카메라 위치 오프셋 (X, Y:높이, Z:거리)")]
    public Vector3 offset = new Vector3(0f, 3.5f, -8.5f);

    [Tooltip("차량을 바라보는 주시점 높이 오프셋 (Pitch 피치 각도 조절 핵심!)")]
    public float lookAtHeightOffset = 1.2f;

    [Header("Pitch Control (상하 각도 틸트 조절)")]
    [Tooltip("추가 수동 상하 피치 각도 보정 (도 단위)")]
    public float pitchAngleOffset = 4.0f;

    [Header("Smooth Settings")]
    public float positionSmoothTime = 0.12f;
    public float rotationSmoothSpeed = 10.0f;

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
        FollowTargetSmooth();
    }

    private void LateUpdate()
    {
        FollowTargetSmooth();
    }

    /// <summary>
    /// 수평 Yaw 회전과 상하 Pitch 피치 각도 조절이 100% 매끄럽게 정밀 조응하는 스무딩 추종
    /// </summary>
    private void FollowTargetSmooth()
    {
        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
            if (targetVehicle == null) return;
        }

        // 1. 차량의 수평(Yaw) 방향 기반 계산
        Vector3 vehicleForward = targetVehicle.forward;
        vehicleForward.y = 0f;
        if (vehicleForward.sqrMagnitude < 0.001f) vehicleForward = transform.forward;
        vehicleForward.Normalize();

        Quaternion yawRotation = Quaternion.LookRotation(vehicleForward, Vector3.up);

        // 2. 원하는 카메라 위치 연산 (차량 위치 + Yaw 회전 오프셋)
        Vector3 desiredPosition = targetVehicle.position + (yawRotation * offset);

        // 3. SmoothDamp 로 위치 묵직하게 스무딩 추종
        transform.position = Vector3.SmoothDamp(transform.position, desiredPosition, ref _currentVelocity, positionSmoothTime);

        // 4. [핵심 Pitch 피치 조절]: 차량 주시점 높이(lookAtHeightOffset)를 바라보는 3D 주시점 벡터 연산
        Vector3 lookTargetPos = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
        Vector3 lookDirection = (lookTargetPos - transform.position).normalized;

        if (lookDirection != Vector3.zero)
        {
            // 상하 Pitch 각도가 반영된 LookRotation 연산
            Quaternion targetRotation = Quaternion.LookRotation(lookDirection, Vector3.up);
            
            // 추가 피치 각도 오프셋(pitchAngleOffset) 합성
            targetRotation *= Quaternion.Euler(pitchAngleOffset, 0f, 0f);

            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.unscaledDeltaTime * rotationSmoothSpeed);
        }
    }
}

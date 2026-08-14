using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;

/// <summary>
/// F5~F8 핫키로 메인 시점을 전환하고,
/// 고속 주행 시에도 좌/우 측면 뷰(F7, F8) 및 탑뷰(F6)가 차 뒤로 단 1mm도 밀리지 않고 
/// 차체 측면 중앙(Center of Vehicle)을 100% 칼같이 바짝 추종하도록 보정한 카메라 컨트롤러.
/// </summary>
public class SmoothCameraController : MonoBehaviour
{
    public static SmoothCameraController Instance { get; private set; }

    public enum CameraViewMode
    {
        Chase,      // F5: 3인칭 기본 추종
        Top,        // F6: 수직 탑뷰
        LeftSide,   // F7: 차체 좌측 완전 수평 Normal 뷰 (무지연 밀림 0% 추종!)
        RightSide,  // F8: 차체 우측 완전 수평 Normal 뷰 (무지연 밀림 0% 추종!)
        Driver,     // 1인칭 실내 뷰
        Orbit       // 마우스 우클릭 자유 궤도 뷰
    }

    [Header("Target Vehicle Reference")]
    public Transform targetVehicle;

    [Header("Current View Mode")]
    public CameraViewMode currentViewMode = CameraViewMode.Chase;

    [Header("Camera Offset Settings (Chase View)")]
    public Vector3 offset = new Vector3(0f, 3.5f, -8.5f);
    public float lookAtHeightOffset = 1.2f;
    public float pitchAngleOffset = 4.0f;

    [Header("Zoom & Orbit Control")]
    public float zoomSensitivity = 2.0f;
    public float minDistance = 3.0f;
    public float maxDistance = 25.0f;
    private float currentZoomOffset = 0f;

    public float orbitSensitivityX = 3.0f;
    public float orbitSensitivityY = 2.0f;
    private float orbitAngleX = 0f;
    private float orbitAngleY = 15f;

    [Header("View Offsets")]
    public float topViewHeight = 25f;
    public Vector3 sideViewOffset = new Vector3(4.8f, 0.0f, 0f);
    public Vector3 driverViewOffset = new Vector3(-0.35f, 1.2f, 0.3f);

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

    private void Update()
    {
        var keyboard = Keyboard.current;
        if (keyboard != null)
        {
            if (keyboard.f5Key.wasPressedThisFrame) SetViewMode(CameraViewMode.Chase);
            if (keyboard.f6Key.wasPressedThisFrame) SetViewMode(CameraViewMode.Top);
            if (keyboard.f7Key.wasPressedThisFrame) SetViewMode(CameraViewMode.LeftSide);
            if (keyboard.f8Key.wasPressedThisFrame) SetViewMode(CameraViewMode.RightSide);

            if (keyboard.vKey.wasPressedThisFrame)
            {
                CycleNextViewMode();
            }
        }

        HandleZoomAndOrbitInput();
    }

    private void HandleZoomAndOrbitInput()
    {
        var mouse = Mouse.current;
        if (mouse == null) return;

        bool isOverSubPanel = (MinimapController.Instance != null && MinimapController.Instance.IsMouseOverMinimap);
        bool isPointerOverUI = (EventSystem.current != null && EventSystem.current.IsPointerOverGameObject()) || isOverSubPanel;

        // 마우스 포인터가 차트, 슬라이딩 HUD, 패널 등 UI 위에 있을 때는 메인 카메라 휠 줌 100% 완전 차단!
        if (!isPointerOverUI)
        {
            float scroll = mouse.scroll.ReadValue().y;
            if (Mathf.Abs(scroll) > 0.1f)
            {
                currentZoomOffset -= Mathf.Sign(scroll) * zoomSensitivity;
                currentZoomOffset = Mathf.Clamp(currentZoomOffset, -6.0f, 15.0f);
            }
        }

        if (mouse.rightButton.isPressed && !isPointerOverUI)
        {
            currentViewMode = CameraViewMode.Orbit;

            Vector2 delta = mouse.delta.ReadValue();
            orbitAngleX += delta.x * orbitSensitivityX * 0.1f;
            orbitAngleY -= delta.y * orbitSensitivityY * 0.1f;
            orbitAngleY = Mathf.Clamp(orbitAngleY, -10f, 80f);
        }
    }

    public void SetViewMode(CameraViewMode mode)
    {
        currentViewMode = mode;
        if (mode == CameraViewMode.Chase)
        {
            currentZoomOffset = 0f;
        }
    }

    public void CycleNextViewMode()
    {
        int nextMode = ((int)currentViewMode + 1) % 4;
        SetViewMode((CameraViewMode)nextMode);
    }

    private void FixedUpdate()
    {
        FollowTargetSmooth();
    }

    private void LateUpdate()
    {
        FollowTargetSmooth();
    }

    private void FollowTargetSmooth()
    {
        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
            if (targetVehicle == null) return;
        }

        Vector3 vehicleForward = targetVehicle.forward;
        vehicleForward.y = 0f;
        if (vehicleForward.sqrMagnitude < 0.001f) vehicleForward = transform.forward;
        vehicleForward.Normalize();

        Quaternion yawRotation = Quaternion.LookRotation(vehicleForward, Vector3.up);

        Vector3 desiredPosition = transform.position;
        Quaternion targetRotation = transform.rotation;

        switch (currentViewMode)
        {
            case CameraViewMode.Chase:
                Vector3 currentOffset = offset;
                currentOffset.z -= currentZoomOffset;
                desiredPosition = targetVehicle.position + (yawRotation * currentOffset);
                Vector3 lookTargetPos = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
                Vector3 lookDir = (lookTargetPos - desiredPosition).normalized;
                if (lookDir != Vector3.zero)
                {
                    targetRotation = Quaternion.LookRotation(lookDir, Vector3.up) * Quaternion.Euler(pitchAngleOffset, 0f, 0f);
                }
                transform.position = Vector3.SmoothDamp(transform.position, desiredPosition, ref _currentVelocity, positionSmoothTime);
                transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.unscaledDeltaTime * rotationSmoothSpeed);
                break;

            case CameraViewMode.Orbit:
                Quaternion orbitRotation = Quaternion.Euler(orbitAngleY, targetVehicle.eulerAngles.y + orbitAngleX, 0f);
                float dist = 8.5f + currentZoomOffset;
                desiredPosition = targetVehicle.position + (orbitRotation * new Vector3(0f, 1.5f, -dist));
                targetRotation = Quaternion.LookRotation((targetVehicle.position + Vector3.up * lookAtHeightOffset) - desiredPosition);
                transform.position = Vector3.SmoothDamp(transform.position, desiredPosition, ref _currentVelocity, positionSmoothTime);
                transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.unscaledDeltaTime * rotationSmoothSpeed);
                break;

            case CameraViewMode.Top:
                float topH = topViewHeight + currentZoomOffset;
                desiredPosition = targetVehicle.position + Vector3.up * topH;
                targetRotation = Quaternion.Euler(90f, targetVehicle.eulerAngles.y, 0f);
                // [밀림 0% 무지연 직통 고정]
                transform.position = desiredPosition;
                transform.rotation = targetRotation;
                break;

            case CameraViewMode.LeftSide:
                // [고속 주행 시 밀림 0% 무지연 차체 정중앙 고정]
                Vector3 leftOffset = new Vector3(-(sideViewOffset.x + currentZoomOffset * 0.5f), 0.0f, sideViewOffset.z);
                desiredPosition = targetVehicle.position + (yawRotation * leftOffset);
                Vector3 leftLookDir = (targetVehicle.position - desiredPosition).normalized;
                leftLookDir.y = 0f;
                targetRotation = Quaternion.LookRotation(leftLookDir, Vector3.up);
                transform.position = desiredPosition;
                transform.rotation = targetRotation;
                break;

            case CameraViewMode.RightSide:
                // [고속 주행 시 밀림 0% 무지연 차체 정중앙 고정]
                Vector3 rightOffset = new Vector3(sideViewOffset.x + currentZoomOffset * 0.5f, 0.0f, sideViewOffset.z);
                desiredPosition = targetVehicle.position + (yawRotation * rightOffset);
                Vector3 rightLookDir = (targetVehicle.position - desiredPosition).normalized;
                rightLookDir.y = 0f;
                targetRotation = Quaternion.LookRotation(rightLookDir, Vector3.up);
                transform.position = desiredPosition;
                transform.rotation = targetRotation;
                break;

            case CameraViewMode.Driver:
                desiredPosition = targetVehicle.position + (targetVehicle.rotation * driverViewOffset);
                targetRotation = targetVehicle.rotation;
                transform.position = desiredPosition;
                transform.rotation = targetRotation;
                break;
        }
    }
}

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
    [Tooltip("1인칭 실내/블랙박스 뷰 오프셋 (X: 좌우, Y: 높이, Z: 전후)")]
    public Vector3 driverViewOffset = new Vector3(-0.35f, 1.15f, -0.15f);

    [Header("Smooth Settings")]
    public float positionSmoothTime = 0.12f;
    public float rotationSmoothSpeed = 10.0f;

    private Vector3 _currentVelocity = Vector3.zero;
    private float _currentCameraYaw = 0f;
    private float _yawVelocity = 0f;

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

        if (targetVehicle != null)
        {
            _currentCameraYaw = targetVehicle.eulerAngles.y;
        }
    }

    private void Update()
    {
        var keyboard = Keyboard.current;
        if (keyboard != null)
        {
            if (keyboard.f5Key.wasPressedThisFrame)
            {
                if (currentViewMode == CameraViewMode.Chase)
                {
                    SetViewMode(CameraViewMode.Driver);
                }
                else
                {
                    SetViewMode(CameraViewMode.Chase);
                }
            }
            if (keyboard.f6Key.wasPressedThisFrame) SetViewMode(CameraViewMode.Top);
            if (keyboard.f7Key.wasPressedThisFrame) SetViewMode(CameraViewMode.LeftSide);
            if (keyboard.f8Key.wasPressedThisFrame) SetViewMode(CameraViewMode.RightSide);

            if (keyboard.vKey.wasPressedThisFrame)
            {
                CycleNextViewMode();
            }
        }

        // 🎮 PowerShift Revolution 휠 핸들 좌측 D-Pad 십자키 (상/하/좌/우) 시점 1:1 직통 매핑!
        var gamepad = Gamepad.current;
        if (gamepad != null)
        {
            // ⬆️ 십자키 위 (D-Pad Up) -> F5 (3인칭 Chase <-> 1인칭 Driver 토글)
            if (gamepad.dpad.up.wasPressedThisFrame)
            {
                if (currentViewMode == CameraViewMode.Chase) SetViewMode(CameraViewMode.Driver);
                else SetViewMode(CameraViewMode.Chase);
            }
            // ⬇️ 십자키 아래 (D-Pad Down) -> Top View (수직 탑뷰)
            if (gamepad.dpad.down.wasPressedThisFrame) SetViewMode(CameraViewMode.Top);

            // ⬅️ 십자키 왼쪽 (D-Pad Left) -> Left View (좌측 사이드 뷰)
            if (gamepad.dpad.left.wasPressedThisFrame) SetViewMode(CameraViewMode.LeftSide);

            // ➡️ 십자키 오른쪽 (D-Pad Right) -> Right View (우측 사이드 뷰)
            if (gamepad.dpad.right.wasPressedThisFrame) SetViewMode(CameraViewMode.RightSide);
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

    // [카메라 지터(Jitter) 원천 방지]:
    // 물리(FixedUpdate, 50Hz) 연산 완료 후 매 렌더링 프레임(60Hz/144Hz) 직전인 LateUpdate 단 하나에서만
    // 차량 위치를 부드럽게 추종하여 프레임 간격 불일치로 인한 떨림을 100% 제거합니다.
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
                // [AAA 레이싱 게임급 각도 기반 극좌표계 체이스 캠]:
                // 1. 차량의 Yaw 회전각을 각도 전용 감쇠기(Mathf.SmoothDampAngle)로 부드럽게 추종합니다.
                // 2. 급조향/원선회 시에도 카메라가 원 안쪽으로 찌그러지지 않고, 항상 차량 뒤쪽 궤도를 완벽한 원호로 감싸며 돕니다.
                float targetYaw = targetVehicle.eulerAngles.y;
                _currentCameraYaw = Mathf.SmoothDampAngle(_currentCameraYaw, targetYaw, ref _yawVelocity, positionSmoothTime);
                Quaternion camYawRot = Quaternion.Euler(0f, _currentCameraYaw, 0f);

                float chaseDistance = Mathf.Abs(offset.z) + currentZoomOffset;
                desiredPosition = targetVehicle.position + (camYawRot * new Vector3(offset.x, offset.y, -chaseDistance));
                transform.position = desiredPosition;

                // 3. 차체 중심을 부드럽게 정조준
                Vector3 lookTargetPos = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
                Vector3 lookDir = (lookTargetPos - transform.position).normalized;
                if (lookDir.sqrMagnitude > 0.001f)
                {
                    transform.rotation = Quaternion.LookRotation(lookDir, Vector3.up) * Quaternion.Euler(pitchAngleOffset, 0f, 0f);
                }
                break;

            case CameraViewMode.Orbit:
                // [자유 시점(Orbit/마우스 우클릭 & 줌) 떨림 100% 원천 제거]:
                // - 마우스 드래그 및 휠 줌 시 3D 선형 스프링(SmoothDamp)의 진동을 제거하고 차체 중심 궤도를 정밀 유지합니다.
                Quaternion orbitRotation = Quaternion.Euler(orbitAngleY, targetVehicle.eulerAngles.y + orbitAngleX, 0f);
                float dist = 8.5f + currentZoomOffset;
                desiredPosition = targetVehicle.position + (orbitRotation * new Vector3(0f, 1.5f, -dist));
                transform.position = desiredPosition;

                Vector3 orbitLookTarget = targetVehicle.position + (Vector3.up * lookAtHeightOffset);
                Vector3 orbitLookDir = (orbitLookTarget - transform.position).normalized;
                if (orbitLookDir.sqrMagnitude > 0.001f)
                {
                    transform.rotation = Quaternion.LookRotation(orbitLookDir, Vector3.up);
                }
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

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using TMPro;

/// <summary>
/// 텔레메트리 우측 계기판 사진 UI 서브 카메라 독립 컨트롤러.
/// 메인 카메라 시점 키(F5~F8)와 100% 독립 구동되며, 초기값은 'TopView(탑뷰)'로 시작합니다.
/// 서브 화면 마우스 클릭 시 [TopView ➔ ChaseView ➔ DriverView(1인칭) ➔ LeftSideView ➔ RightSideView] 5가지 시점이 독립 순환됩니다.
/// </summary>
public class MinimapController : MonoBehaviour
{
    public static MinimapController Instance { get; private set; }

    public enum SubViewMode
    {
        TopView = 0,       // 기본 초기값 (서브 탑뷰)
        ChaseView = 1,     // 3D 후방 추적 뷰
        DriverView = 2,    // 1인칭 운전석 뷰
        LeftSideView = 3,  // 좌측 사이드 뷰
        RightSideView = 4  // 우측 사이드 뷰
    }

    [Header("Target References")]
    public Transform targetVehicle;
    public Camera subCamera;

    [Header("UI Text (Option)")]
    public TextMeshProUGUI viewModeLabelText;

    [Header("State")]
    [Tooltip("서브 카메라 기본 초기값: TopView (탑뷰)")]
    public SubViewMode currentSubMode = SubViewMode.TopView;
    public bool IsMouseOverMinimap { get; private set; }

    [Header("Sub Camera Distance Control")]
    public float topHeight = 18f;
    public float sideDistance = 4.8f;
    public float chaseDistance = 6.5f;
    public float chaseHeight = 2.8f;
    [Tooltip("서브 카메라 1인칭 실내/블랙박스 뷰 오프셋 (X: 좌우, Y: 높이, Z: 전후)")]
    public Vector3 driverViewOffset = new Vector3(-0.35f, 1.15f, -0.15f);

    private RectTransform _rectTransform;

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

        _rectTransform = GetComponent<RectTransform>();
    }

    private void Start()
    {
        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
        }

        currentSubMode = SubViewMode.TopView;

        CreateSubCameraIfNull();
        AutoAttachButtonToRenderTextureUI();
        UpdateViewModeLabel();
    }

    private void CreateSubCameraIfNull()
    {
        if (subCamera == null)
        {
            GameObject camObj = GameObject.Find("SubViewportCamera");
            if (camObj == null) camObj = new GameObject("SubViewportCamera");
            
            subCamera = camObj.GetComponent<Camera>();
            if (subCamera == null) subCamera = camObj.AddComponent<Camera>();

            subCamera.clearFlags = CameraClearFlags.Skybox;
            subCamera.fieldOfView = 60f;

            RenderTexture rt = Resources.Load<RenderTexture>("MinimapRenderTexture");
            if (rt != null)
            {
                subCamera.targetTexture = rt;
            }
        }
    }

    private void AutoAttachButtonToRenderTextureUI()
    {
        RawImage[] rawImages = FindObjectsByType<RawImage>(FindObjectsSortMode.None);
        foreach (RawImage rawImg in rawImages)
        {
            if (rawImg.texture != null && rawImg.texture.name.Contains("Minimap"))
            {
                rawImg.raycastTarget = true;
                
                Button btn = rawImg.GetComponent<Button>();
                if (btn == null)
                {
                    btn = rawImg.gameObject.AddComponent<Button>();
                }

                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(() => {
                    SwitchToNextSubView();
                });

                _rectTransform = rawImg.GetComponent<RectTransform>();
                return;
            }
        }

        EnsureRaycastTargetAndButton(gameObject);
    }

    private void EnsureRaycastTargetAndButton(GameObject targetObj)
    {
        Graphic g = targetObj.GetComponent<Graphic>();
        if (g != null) g.raycastTarget = true;

        Button btn = targetObj.GetComponent<Button>();
        if (btn == null) btn = targetObj.AddComponent<Button>();

        btn.onClick.RemoveAllListeners();
        btn.onClick.AddListener(() => {
            SwitchToNextSubView();
        });
    }

    private void Update()
    {
        CheckMouseHoverAndSubZoom();

        // 🟢 X 버튼 -> Telemetry HUD 미니 뷰포트 서브 카메라 시점 1:1 순환 변경!
        var gamepad = Gamepad.current;
        if (gamepad != null && gamepad.buttonWest.wasPressedThisFrame)
        {
            SwitchToNextSubView();
        }
    }

    public void SetSubViewMode(SubViewMode mode)
    {
        currentSubMode = mode;
        UpdateViewModeLabel();
    }

    private void CheckMouseHoverAndSubZoom()
    {
        if (_rectTransform == null) return;

        Vector2 mousePos = Vector2.zero;
        if (Mouse.current != null)
        {
            mousePos = Mouse.current.position.ReadValue();
        }

        IsMouseOverMinimap = RectTransformUtility.RectangleContainsScreenPoint(_rectTransform, mousePos);

        if (IsMouseOverMinimap && Mouse.current != null)
        {
            float scroll = Mouse.current.scroll.ReadValue().y;
            if (Mathf.Abs(scroll) > 0.1f)
            {
                float zoomDelta = Mathf.Sign(scroll) * 1.5f;
                topHeight = Mathf.Clamp(topHeight - zoomDelta, 5f, 60f);
                sideDistance = Mathf.Clamp(sideDistance - zoomDelta * 0.2f, 2.0f, 15.0f);
                chaseDistance = Mathf.Clamp(chaseDistance - zoomDelta * 0.2f, 2.0f, 20.0f);
            }
        }
    }

    /// <summary>
    /// 오직 서브 화면 마우스 클릭 시에만 5가지 독립 시점 순환 [TopView ➔ ChaseView ➔ DriverView(1인칭) ➔ LeftView ➔ RightView]
    /// </summary>
    public void SwitchToNextSubView()
    {
        int next = ((int)currentSubMode + 1) % 5;
        currentSubMode = (SubViewMode)next;
        UpdateViewModeLabel();
    }

    private void UpdateViewModeLabel()
    {
        if (viewModeLabelText != null)
        {
            switch (currentSubMode)
            {
                case SubViewMode.TopView: viewModeLabelText.text = "📷 SUB: TOP VIEW"; break;
                case SubViewMode.ChaseView: viewModeLabelText.text = "📷 SUB: CHASE VIEW"; break;
                case SubViewMode.DriverView: viewModeLabelText.text = "📷 SUB: DRIVER VIEW"; break;
                case SubViewMode.LeftSideView: viewModeLabelText.text = "📷 SUB: LEFT VIEW"; break;
                case SubViewMode.RightSideView: viewModeLabelText.text = "📷 SUB: RIGHT VIEW"; break;
            }
        }
    }

    private void LateUpdate()
    {
        if (targetVehicle == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) targetVehicle = vc.transform;
            if (targetVehicle == null) return;
        }

        if (subCamera == null) return;

        Vector3 vForward = targetVehicle.forward;
        vForward.y = 0f;
        if (vForward.sqrMagnitude < 0.001f) vForward = Vector3.forward;
        vForward.Normalize();
        Quaternion yawRot = Quaternion.LookRotation(vForward, Vector3.up);

        switch (currentSubMode)
        {
            case SubViewMode.TopView:
                subCamera.transform.position = targetVehicle.position + Vector3.up * topHeight;
                subCamera.transform.rotation = Quaternion.Euler(90f, targetVehicle.eulerAngles.y, 0f);
                subCamera.orthographic = false;
                break;

            case SubViewMode.ChaseView:
                Vector3 chaseOff = new Vector3(0f, chaseHeight, -chaseDistance);
                subCamera.transform.position = targetVehicle.position + (yawRot * chaseOff);
                Vector3 chaseLookDir = (targetVehicle.position + Vector3.up * 1.2f - subCamera.transform.position).normalized;
                subCamera.transform.rotation = Quaternion.LookRotation(chaseLookDir, Vector3.up);
                subCamera.orthographic = false;
                break;

            case SubViewMode.DriverView:
                subCamera.transform.position = targetVehicle.position + (targetVehicle.rotation * driverViewOffset);
                subCamera.transform.rotation = targetVehicle.rotation;
                subCamera.orthographic = false;
                break;

            case SubViewMode.LeftSideView:
                Vector3 leftOff = new Vector3(-sideDistance, 0.0f, 0f);
                subCamera.transform.position = targetVehicle.position + (yawRot * leftOff);
                Vector3 leftLookDir = (targetVehicle.position - subCamera.transform.position).normalized;
                leftLookDir.y = 0f;
                subCamera.transform.rotation = Quaternion.LookRotation(leftLookDir, Vector3.up);
                subCamera.orthographic = false;
                break;

            case SubViewMode.RightSideView:
                Vector3 rightOff = new Vector3(sideDistance, 0.0f, 0f);
                subCamera.transform.position = targetVehicle.position + (yawRot * rightOff);
                Vector3 rightLookDir = (targetVehicle.position - subCamera.transform.position).normalized;
                rightLookDir.y = 0f;
                subCamera.transform.rotation = Quaternion.LookRotation(rightLookDir, Vector3.up);
                subCamera.orthographic = false;
                break;
        }
    }
}

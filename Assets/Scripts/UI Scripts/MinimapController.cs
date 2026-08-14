using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using TMPro;

/// <summary>
/// 텔레메트리 우측 계기판 사진 UI 서브 카메라 모니터 컨트롤러.
/// (TopView ➔ ChaseView ➔ LeftSideView ➔ RightSideView) 4가지 정갈한 서브 뷰모드를 지원합니다.
/// </summary>
public class MinimapController : MonoBehaviour
{
    public static MinimapController Instance { get; private set; }

    public enum SubViewMode
    {
        TopView,
        ChaseView,
        LeftSideView,
        RightSideView
    }

    [Header("Target References")]
    public Transform targetVehicle;
    public Camera subCamera;

    [Header("UI Text (Option)")]
    public TextMeshProUGUI viewModeLabelText;

    [Header("State")]
    public SubViewMode currentSubMode = SubViewMode.TopView;
    public bool IsMouseOverMinimap { get; private set; }

    [Header("Sub Camera Distance Control")]
    public float topHeight = 18f;
    public float sideDistance = 4.8f;
    public float chaseDistance = 6.0f;
    public float chaseHeight = 2.5f;

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
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null) targetVehicle = vc.transform;

        if (subCamera == null)
        {
            subCamera = GameObject.Find("MinimapCamera")?.GetComponent<Camera>();
        }

        UpdateViewModeLabel();
    }

    public void OnPointerEnter(BaseEventData eventData)
    {
        IsMouseOverMinimap = true;
    }

    public void OnPointerExit(BaseEventData eventData)
    {
        IsMouseOverMinimap = false;
    }

    public void OnPointerClick(BaseEventData eventData)
    {
        PointerEventData pData = eventData as PointerEventData;
        if (pData != null && pData.button == PointerEventData.InputButton.Left)
        {
            SwitchToNextSubView();
        }
    }

    private void Update()
    {
        if (IsMouseOverMinimap && Mouse.current != null)
        {
            float zoomDelta = Mouse.current.scroll.ReadValue().y;
            if (Mathf.Abs(zoomDelta) > 0.01f)
            {
                if (currentSubMode == SubViewMode.TopView)
                {
                    topHeight = Mathf.Clamp(topHeight - zoomDelta * 0.5f, 5.0f, 80.0f);
                }
                else if (currentSubMode == SubViewMode.ChaseView)
                {
                    chaseDistance = Mathf.Clamp(chaseDistance - zoomDelta * 0.2f, 2.0f, 20.0f);
                }
                else
                {
                    sideDistance = Mathf.Clamp(sideDistance - zoomDelta * 0.2f, 2.0f, 15.0f);
                }
            }
        }
    }

    public void SwitchToNextSubView()
    {
        int next = ((int)currentSubMode + 1) % 4;
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
                Vector3 chaseLookDir = (targetVehicle.position + Vector3.up * 1.0f - subCamera.transform.position).normalized;
                subCamera.transform.rotation = Quaternion.LookRotation(chaseLookDir, Vector3.up);
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

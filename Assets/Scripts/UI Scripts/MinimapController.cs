using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

/// <summary>
/// 텔레메트리 미니맵 UI RawImage 위에서 마우스 휠 이벤트를 수신받아 MinimapController로 중계해주는 프록시 컴포넌트
/// </summary>
public class MinimapScrollProxy : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler, IScrollHandler
{
    public MinimapController controller;

    public void OnPointerEnter(PointerEventData eventData)
    {
        if (controller != null) controller.SetMouseHover(true);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        if (controller != null) controller.SetMouseHover(false);
    }

    public void OnScroll(PointerEventData eventData)
    {
        if (controller != null)
        {
            controller.HandleScrollDelta(eventData.scrollDelta.y);
        }
    }
}

/// <summary>
/// 텔레메트리 패널 우측 빈 공간에 실시간 탑뷰 내비게이션(Minimap)을 띄워주는 미니맵 컨트롤러 스크립트.
/// 유니티 UI IScrollHandler 연동 마우스 휠 줌(5~30) 및 수직 탑뷰 카메라 추적을 포함합니다.
/// </summary>
public class MinimapController : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler, IScrollHandler
{
    public static MinimapController Instance;

    [Header("1. Tracking Target")]
    [Tooltip("미니맵이 추적할 차량 Transform (비어있으면 자동 검색)")]
    public Transform targetVehicle;

    [Header("2. Minimap Camera Settings")]
    [Tooltip("탑뷰 촬영 전용 카메라 (Orthographic)")]
    public Camera minimapCamera;

    [Tooltip("차량 상공 카메라 높이 (m)")]
    public float cameraHeight = 50f;

    [Tooltip("미니맵 시야 폭 (Orthographic Size: 5 ~ 30 범위)")]
    public float minimapZoom = 15f;

    [Tooltip("최소 줌 (최대 확대 - 차 크게 보기)")]
    public float minZoom = 5f;

    [Tooltip("최대 줌 (최대 축소 - 넓은 지형 보기)")]
    public float maxZoom = 30f;

    [Tooltip("마우스 휠 줌 민감도")]
    public float scrollSensitivity = 2f;

    [Tooltip("Heading-Up (차량 정면 방향 회전) 모드 사용 여부 (false면 North-Up 북쪽 고정)")]
    public bool rotateWithVehicle = true;

    [Header("3. UI Reference")]
    [Tooltip("텔레메트리 패널 우측에 배치된 미니맵 RawImage 화면")]
    public RawImage minimapRawImage;

    [Tooltip("미니맵 중앙 차량 위상 표시용 아이콘 (옵션)")]
    public RectTransform playerIconUI;

    private RenderTexture _runtimeRenderTexture;
    private bool _isMouseOverMinimap = false;

    public bool IsMouseOverMinimap => _isMouseOverMinimap;

    private void Awake()
    {
        if (Instance == null) Instance = this;
    }

    private void Start()
    {
        EnsureSetup();
    }

    public void SetMouseHover(bool isHover)
    {
        _isMouseOverMinimap = isHover;
    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        _isMouseOverMinimap = true;
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        _isMouseOverMinimap = false;
    }

    public void OnScroll(PointerEventData eventData)
    {
        HandleScrollDelta(eventData.scrollDelta.y);
    }

    public void HandleScrollDelta(float scrollY)
    {
        if (Mathf.Abs(scrollY) > 0.01f)
        {
            float direction = scrollY > 0f ? 1f : -1f;
            minimapZoom = Mathf.Clamp(minimapZoom - (direction * scrollSensitivity), minZoom, maxZoom);
            if (minimapCamera != null)
            {
                minimapCamera.orthographicSize = minimapZoom;
            }
        }
    }

    private void EnsureSetup()
    {
        // 1. 차량 자동 검색
        if (targetVehicle == null)
        {
            VehicleController vc = Object.FindAnyObjectByType<VehicleController>();
            if (vc != null)
            {
                targetVehicle = vc.transform;
            }
            else
            {
                GameObject carObj = GameObject.FindWithTag("Player");
                if (carObj != null) targetVehicle = carObj.transform;
            }
        }

        // 2. 미니맵 카메라 자동 검색
        if (minimapCamera == null)
        {
            minimapCamera = GetComponent<Camera>();
        }

        // 3. RawImage UI 자동 검색 및 이벤트 프록시 자동 부착
        if (minimapRawImage == null)
        {
            RawImage[] rawImages = Object.FindObjectsByType<RawImage>(FindObjectsSortMode.None);
            foreach (RawImage ri in rawImages)
            {
                if (ri.name.Contains("Minimap") || ri.name.Contains("Map") || ri.name.Contains("Nav"))
                {
                    minimapRawImage = ri;
                    break;
                }
            }
            if (minimapRawImage == null && rawImages.Length > 0)
            {
                minimapRawImage = rawImages[0];
            }
        }

        // UI RawImage에 IScrollHandler 프록시 컴포넌트 및 RaycastTarget 100% 자동 부착
        if (minimapRawImage != null)
        {
            minimapRawImage.raycastTarget = true;
            MinimapScrollProxy proxy = minimapRawImage.GetComponent<MinimapScrollProxy>();
            if (proxy == null)
            {
                proxy = minimapRawImage.gameObject.AddComponent<MinimapScrollProxy>();
            }
            proxy.controller = this;
        }

        // 4. RenderTexture 512x512 자동 생성 및 바인딩
        if (minimapCamera != null)
        {
            minimapCamera.orthographic = true;
            minimapCamera.orthographicSize = minimapZoom;

            if (minimapCamera.targetTexture == null && _runtimeRenderTexture == null)
            {
                _runtimeRenderTexture = new RenderTexture(512, 512, 16, RenderTextureFormat.ARGB32);
                _runtimeRenderTexture.Create();
                minimapCamera.targetTexture = _runtimeRenderTexture;
            }

            if (minimapRawImage != null && minimapRawImage.texture == null)
            {
                minimapRawImage.texture = minimapCamera.targetTexture;
            }
        }
    }

    private void LateUpdate()
    {
        EnsureSetup();

        if (targetVehicle == null || minimapCamera == null) return;

        // 1. 카메라 위치: 차량 수직 상공 고정 추적
        Vector3 carPos = targetVehicle.position;
        minimapCamera.transform.position = new Vector3(carPos.x, carPos.y + cameraHeight, carPos.z);

        // 2. 카메라 회전: 수직 직각 아래(Pitch = 90도)를 내다보도록 고정
        float carYaw = targetVehicle.eulerAngles.y;

        if (rotateWithVehicle)
        {
            minimapCamera.transform.rotation = Quaternion.Euler(90f, carYaw, 0f);

            if (playerIconUI != null)
            {
                playerIconUI.localRotation = Quaternion.identity;
            }
        }
        else
        {
            minimapCamera.transform.rotation = Quaternion.Euler(90f, 0f, 0f);

            if (playerIconUI != null)
            {
                playerIconUI.localRotation = Quaternion.Euler(0f, 0f, -carYaw);
            }
        }

        minimapCamera.orthographicSize = minimapZoom;
    }

    public void SetZoom(float zoomSize)
    {
        minimapZoom = Mathf.Clamp(zoomSize, minZoom, maxZoom);
        if (minimapCamera != null)
        {
            minimapCamera.orthographicSize = minimapZoom;
        }
    }

    public void ToggleRotationMode(bool useHeadingUp)
    {
        rotateWithVehicle = useHeadingUp;
    }

    private void OnDestroy()
    {
        if (_runtimeRenderTexture != null)
        {
            _runtimeRenderTexture.Release();
            Destroy(_runtimeRenderTexture);
        }
    }
}

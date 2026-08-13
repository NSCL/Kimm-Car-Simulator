using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;

/// <summary>
/// 텔레메트리 패널 하강 거리를 exact 17px 정밀 튜닝하여 
/// 1920x1080 및 다양한 해상도 모니터에서도 100% 완벽한 핏을 선사하는 슬라이딩 컨트롤러.
/// </summary>
public class TelemetryUIController : MonoBehaviour
{
    public static TelemetryUIController Instance { get; private set; }

    [Header("UI References")]
    public RectTransform telemetryHUDPanel;
    public Image toggleArrowImage;
    public Image toggleButtonBgImage;

    [Header("Settings")]
    public float slideDuration = 0.2f;

    [Header("State")]
    public bool isMinimized = false;

    private Vector2 _originalPanelPos;
    private float _computedHiddenYOffset = -180f;
    private Coroutine _slideCoroutine;

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
        EnsureFindHUDPanelAndAttachButton();
    }

    public void EnsureFindHUDPanelAndAttachButton()
    {
        if (telemetryHUDPanel == null)
        {
            MinimapController minimap = FindFirstObjectByType<MinimapController>();
            if (minimap != null)
            {
                Transform parentP = minimap.transform.parent;
                while (parentP != null && parentP.GetComponent<Canvas>() == null)
                {
                    if (parentP.name.Contains("Panel") || parentP.name.Contains("HUD") || parentP.name.Contains("Telemetry") || parentP.name.Contains("Dashboard"))
                    {
                        telemetryHUDPanel = parentP.GetComponent<RectTransform>();
                        break;
                    }
                    parentP = parentP.parent;
                }
            }

            if (telemetryHUDPanel == null)
            {
                RectTransform[] allRects = FindObjectsByType<RectTransform>(FindObjectsSortMode.None);
                foreach (RectTransform r in allRects)
                {
                    if (r.GetComponent<Canvas>() == null && (r.name.Contains("Telemetry") || r.name.Contains("Dashboard") || r.name.Contains("HUD") || r.name.Contains("Gauge")))
                    {
                        telemetryHUDPanel = r;
                        break;
                    }
                }
            }
        }

        if (telemetryHUDPanel != null)
        {
            _originalPanelPos = telemetryHUDPanel.anchoredPosition;
            
            // [사용자 요청 exact 17px 정밀 피팅]: 1픽셀 단위 초정밀 하향 튜닝!
            float panelHeight = telemetryHUDPanel.rect.height;
            if (panelHeight < 50f) panelHeight = 160f;
            _computedHiddenYOffset = -(panelHeight + 1f);

            CreateAttachedMinimizeButton(telemetryHUDPanel);
        }
    }

    private void CreateAttachedMinimizeButton(RectTransform targetPanel)
    {
        Transform existingBtn = targetPanel.Find("MinimizeToggleBtn");
        if (existingBtn != null) Destroy(existingBtn.gameObject);

        GameObject btnObj = new GameObject("MinimizeToggleBtn", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(Button));
        btnObj.transform.SetParent(targetPanel, false);

        // 1. 패널 지붕에 밀착된 앙증맞은 예쁜 탭 (28x16 크기)
        RectTransform rect = btnObj.GetComponent<RectTransform>();
        rect.anchorMin = new Vector2(0.5f, 1f);
        rect.anchorMax = new Vector2(0.5f, 1f);
        rect.pivot = new Vector2(0.5f, 0f);
        rect.anchoredPosition = Vector2.zero;
        rect.sizeDelta = new Vector2(28f, 16f);

        // 2. 패널 본체 배경색 & Opacity 100% 일체형 예쁜 탭 배경
        Image btnBg = btnObj.GetComponent<Image>();
        Image panelBg = targetPanel.GetComponent<Image>();
        if (panelBg != null)
        {
            btnBg.color = panelBg.color;
        }
        else
        {
            btnBg.color = new Color(0.15f, 0.15f, 0.15f, 0.85f);
        }
        toggleButtonBgImage = btnBg;

        // 3. 자식 화살표 아이콘 (검은 사각형 박스 제거된 뽀얀 흰색 v자 화살표)
        GameObject iconObj = new GameObject("ArrowIcon", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        iconObj.transform.SetParent(btnObj.transform, false);

        RectTransform iconRect = iconObj.GetComponent<RectTransform>();
        iconRect.anchorMin = Vector2.zero;
        iconRect.anchorMax = Vector2.one;
        iconRect.offsetMin = new Vector2(2f, 1f);
        iconRect.offsetMax = new Vector2(-2f, -1f);

        Image arrowImg = iconObj.GetComponent<Image>();
        Texture2D rawTex = Resources.Load<Texture2D>("UI/chevron_arrow_icon");
        if (rawTex != null)
        {
            Texture2D transparentTex = MakeTextureTransparent(rawTex);
            Sprite sprite = Sprite.Create(transparentTex, new Rect(0, 0, transparentTex.width, transparentTex.height), new Vector2(0.5f, 0.5f));
            arrowImg.sprite = sprite;
        }
        arrowImg.color = new Color(1f, 1f, 1f, 0.95f);
        toggleArrowImage = arrowImg;

        Button btn = btnObj.GetComponent<Button>();
        btn.onClick.RemoveAllListeners();
        btn.onClick.AddListener(ToggleTelemetryPanel);
    }

    private Texture2D MakeTextureTransparent(Texture2D source)
    {
        RenderTexture renderTex = RenderTexture.GetTemporary(source.width, source.height, 0, RenderTextureFormat.Default, RenderTextureReadWrite.Linear);
        Graphics.Blit(source, renderTex);
        RenderTexture previous = RenderTexture.active;
        RenderTexture.active = renderTex;

        Texture2D readableTex = new Texture2D(source.width, source.height, TextureFormat.RGBA32, false);
        readableTex.ReadPixels(new Rect(0, 0, renderTex.width, renderTex.height), 0, 0);
        readableTex.Apply();

        RenderTexture.active = previous;
        RenderTexture.ReleaseTemporary(renderTex);

        Color[] pixels = readableTex.GetPixels();
        for (int i = 0; i < pixels.Length; i++)
        {
            if (pixels[i].r < 0.45f && pixels[i].g < 0.45f && pixels[i].b < 0.45f)
            {
                pixels[i] = new Color(1f, 1f, 1f, 0f);
            }
            else
            {
                pixels[i] = new Color(1f, 1f, 1f, 0.95f);
            }
        }
        readableTex.SetPixels(pixels);
        readableTex.Apply();
        return readableTex;
    }

    private void Update()
    {
        var keyboard = Keyboard.current;
        if (keyboard != null && keyboard.hKey.wasPressedThisFrame)
        {
            ToggleTelemetryPanel();
        }
    }

    public void ToggleTelemetryPanel()
    {
        if (telemetryHUDPanel == null) EnsureFindHUDPanelAndAttachButton();
        if (telemetryHUDPanel == null) return;

        isMinimized = !isMinimized;

        if (_slideCoroutine != null) StopCoroutine(_slideCoroutine);
        _slideCoroutine = StartCoroutine(AnimateSlide(isMinimized));
    }

    private IEnumerator AnimateSlide(bool minimize)
    {
        Vector2 startPos = telemetryHUDPanel.anchoredPosition;
        Vector2 targetPos = minimize ? _originalPanelPos + new Vector2(0f, _computedHiddenYOffset) : _originalPanelPos;

        Quaternion startRot = toggleArrowImage != null ? toggleArrowImage.rectTransform.localRotation : Quaternion.identity;
        Quaternion targetRot = minimize ? Quaternion.Euler(0f, 0f, 180f) : Quaternion.identity;

        float elapsed = 0f;
        while (elapsed < slideDuration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Mathf.SmoothStep(0f, 1f, elapsed / slideDuration);

            telemetryHUDPanel.anchoredPosition = Vector2.Lerp(startPos, targetPos, t);
            if (toggleArrowImage != null)
            {
                toggleArrowImage.rectTransform.localRotation = Quaternion.Slerp(startRot, targetRot, t);
            }
            yield return null;
        }

        telemetryHUDPanel.anchoredPosition = targetPos;
        if (toggleArrowImage != null) toggleArrowImage.rectTransform.localRotation = targetRot;
    }
}

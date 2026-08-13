using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;

/// <summary>
/// 텔레메트리 패널 지붕에 상단 모서리가 부드럽고 앙증맞은 둥근 모서리 탭(Rounded Corner Tab) 버튼을 자동 렌더링하고,
/// 패널 본체 상단 비침 0% 및 부드러운 슬라이딩 접기/펼치기를 수행하는 컨트롤러.
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

        // 2. 상단 모서리가 부드럽고 둥글둥글한 둥근 모서리(Rounded Corners) 탭 스프라이트 렌더링
        Image btnBg = btnObj.GetComponent<Image>();
        Texture2D roundedTex = MakeRoundedTabTexture(64, 36, 12);
        Sprite roundedSprite = Sprite.Create(roundedTex, new Rect(0, 0, roundedTex.width, roundedTex.height), new Vector2(0.5f, 0f));
        btnBg.sprite = roundedSprite;
        btnBg.type = Image.Type.Simple;

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

    /// <summary>
    /// 상단 왼쪽/우측 모서리만 둥글둥글하게 라운딩(Rounded Top Corners)된 세련된 탭 텍스처 런타임 생성기
    /// </summary>
    private Texture2D MakeRoundedTabTexture(int width, int height, int radius)
    {
        Texture2D tex = new Texture2D(width, height, TextureFormat.RGBA32, false);
        Color[] colors = new Color[width * height];

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                bool inside = true;

                // 상단 좌측 둥근 모서리 검사
                if (x < radius && y > (height - radius))
                {
                    float dx = radius - x;
                    float dy = y - (height - radius);
                    if (dx * dx + dy * dy > radius * radius) inside = false;
                }
                // 상단 우측 둥근 모서리 검사
                else if (x > (width - radius) && y > (height - radius))
                {
                    float dx = x - (width - radius);
                    float dy = y - (height - radius);
                    if (dx * dx + dy * dy > radius * radius) inside = false;
                }

                colors[y * width + x] = inside ? Color.white : new Color(1f, 1f, 1f, 0f);
            }
        }

        tex.SetPixels(colors);
        tex.Apply();
        return tex;
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

using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 맵 전환(MapChanger) 진행 중 및 씬 최초 시작 시 화면 상하좌우 4개 모서리까지 1픽셀 오차 없이 100% 완전 불투명(100% Opaque) 
/// 오버플로우 다크 커튼으로 가려주는 런타임 UI 로더.
/// </summary>
public class LoadingPanelUI : MonoBehaviour
{
    public static LoadingPanelUI Instance { get; private set; }

    [Header("UI Panel Reference")]
    [Tooltip("로딩 중일 때 표시할 최상단 Loading UI 패널")]
    public GameObject loadingPanel;

    [Header("Optional UI Elements")]
    [Tooltip("로딩 텍스트 (예: Loading Map... 75%)")]
    public TextMeshProUGUI loadingText;

    [Tooltip("로딩 프로그레스 바 슬라이더 (옵션)")]
    public Slider loadingSlider;

    [Header("Settings")]
    public string defaultLoadingMessage = "Loading Initial Map...";

    private Coroutine progressCoroutine;

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

        // [100% 완전 불투명 꽉 찬 로딩 오버레이 촥 적용]
        EnsureFullOpaqueOverlay();
    }

    private void Start()
    {
        // 씬 시작과 동시에 100% 완전 불투명 로딩 오버레이 발동!
        ShowLoadingUI();

        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted += ShowLoadingUI;
            MapChanger.Instance.OnMapChangeCompleted += HideLoadingUI;
        }
    }

    private void EnsureFullOpaqueOverlay()
    {
        if (loadingPanel == null) return;

        Image panelImg = loadingPanel.GetComponent<Image>();
        if (panelImg != null)
        {
            panelImg.sprite = null; // 텍스처 투명 자국 원천 차단
            panelImg.color = new Color(0.05f, 0.05f, 0.05f, 1.0f); // 100% 불투명 다크
        }

        RectTransform rt = loadingPanel.GetComponent<RectTransform>();
        if (rt != null)
        {
            rt.anchorMin = Vector2.zero;
            rt.anchorMax = Vector2.one;
            rt.offsetMin = new Vector2(-100f, -100f); // 상하좌우 100px 오버플로우 100% 차단
            rt.offsetMax = new Vector2(100f, 100f);
        }
    }

    private void OnDestroy()
    {
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted -= ShowLoadingUI;
            MapChanger.Instance.OnMapChangeCompleted -= HideLoadingUI;
        }
    }

    public void ShowLoadingUI()
    {
        if (loadingPanel != null)
        {
            EnsureFullOpaqueOverlay();
            loadingPanel.SetActive(true);
            if (loadingText != null) loadingText.text = defaultLoadingMessage;
            if (loadingSlider != null) loadingSlider.value = 0f;
        }

        if (progressCoroutine != null) StopCoroutine(progressCoroutine);
        progressCoroutine = StartCoroutine(AnimateProgressRoutine());
    }

    public void HideLoadingUI()
    {
        if (progressCoroutine != null)
        {
            StopCoroutine(progressCoroutine);
            progressCoroutine = null;
        }

        if (loadingPanel != null)
        {
            loadingPanel.SetActive(false);
        }
    }

    private IEnumerator AnimateProgressRoutine()
    {
        float timer = 0f;
        float duration = 1.0f;

        while (timer < duration)
        {
            timer += Time.unscaledDeltaTime;
            float progress = Mathf.Clamp01(timer / duration);

            if (loadingSlider != null) loadingSlider.value = progress;
            if (loadingText != null) loadingText.text = $"Loading Map... {(int)(progress * 100)}%";

            yield return null;
        }

        if (loadingSlider != null) loadingSlider.value = 1f;
        if (loadingText != null) loadingText.text = "Loading Complete!";

        yield return new WaitForSecondsRealtime(0.2f);
        HideLoadingUI();
    }
}

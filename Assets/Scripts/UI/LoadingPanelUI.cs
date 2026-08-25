using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 시놀로지 NAS 네트워크 로딩 환경 및 맵 전환 시 
/// 실제로 맵 비동기 로딩과 3D 물리 최적화가 100% 완료될 때까지 불투명 로딩 커튼을 유지하는 런타임 UI 로더.
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

        EnsureFullOpaqueOverlay();
    }

    private void Start()
    {
        ShowLoadingUI(0.0f);

        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted += OnMapChangeStartedHandler;
            MapChanger.Instance.OnMapChangeCompleted += OnMapChangeCompletedHandler;
        }
    }

    private void EnsureFullOpaqueOverlay()
    {
        if (loadingPanel == null) return;

        Image panelImg = loadingPanel.GetComponent<Image>();
        if (panelImg != null)
        {
            panelImg.sprite = null;
            panelImg.color = new Color(0.05f, 0.05f, 0.05f, 1.0f);
        }

        RectTransform rt = loadingPanel.GetComponent<RectTransform>();
        if (rt != null)
        {
            rt.anchorMin = Vector2.zero;
            rt.anchorMax = Vector2.one;
            rt.offsetMin = new Vector2(-100f, -100f);
            rt.offsetMax = new Vector2(100f, 100f);
        }
    }

    private void OnDestroy()
    {
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted -= OnMapChangeStartedHandler;
            MapChanger.Instance.OnMapChangeCompleted -= OnMapChangeCompletedHandler;
        }
    }

    private void OnMapChangeStartedHandler()
    {
        ShowLoadingUI(0.0f);
    }

    private void OnMapChangeCompletedHandler()
    {
        StartCoroutine(HideRoutine());
    }

    private IEnumerator HideRoutine()
    {
        UpdateProgressUI(1.0f);
        yield return new WaitForSecondsRealtime(0.2f);
        HideLoadingUI();
    }

    public void ShowLoadingUI(float initialProgress = 0.0f)
    {
        if (loadingPanel != null)
        {
            EnsureFullOpaqueOverlay();
            loadingPanel.SetActive(true);
            UpdateProgressUI(initialProgress);
        }
    }

    /// <summary>
    /// MapChanger에서 전달하는 실제 비동기 로딩 및 3D 물리 최적화 진행률(0.0~1.0)을 1:1 실시간 갱신
    /// </summary>
    public void SetProgress(float progress)
    {
        UpdateProgressUI(progress);
    }

    private void UpdateProgressUI(float progress)
    {
        float clampedProgress = Mathf.Clamp01(progress);
        int percentage = Mathf.RoundToInt(clampedProgress * 100f);

        if (loadingSlider != null)
        {
            loadingSlider.value = clampedProgress;
        }

        if (loadingText != null)
        {
            loadingText.text = $"Loading Map... {percentage}%";
        }
    }

    public void HideLoadingUI()
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(false);
        }
    }
}

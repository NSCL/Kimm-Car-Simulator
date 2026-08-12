using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 맵 전환(MapChanger) 진행 중일 때 화면 테두리 및 4개 모서리까지 1픽셀의 오차도 없이 100% 완전 불투명(100% Opaque) 
/// 오버플로우 다크 화면으로 가려주는 런타임 UI 로더.
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
    public string defaultLoadingMessage = "Loading Map...";

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
    }

    private void Start()
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(false);
        }

        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted += ShowLoadingUI;
            MapChanger.Instance.OnMapChangeCompleted += HideLoadingUI;
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

    /// <summary>
    /// 맵 로딩 시작 시 호출 (화면 상하좌우 테두리와 4개 모서리 픽셀까지 100% 완벽히 가림)
    /// </summary>
    public void ShowLoadingUI()
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(true);

            // [핵심 100% 차단 보완 1]: 둥근 모서리 스프라이트 지우기 (순수 직사각형으로 변경)
            Image img = loadingPanel.GetComponent<Image>();
            if (img != null)
            {
                img.sprite = null; // 둥근 템플릿 제거
                img.color = new Color(0.08f, 0.09f, 0.12f, 1f); // #14171F 불투명 다크 컬러
            }

            // [핵심 100% 차단 보완 2]: 화면 크기보다 상하좌우 100px씩 더 밖으로 돌출(Overfill)시켜 모서리 틈새 100% 차단!
            RectTransform rt = loadingPanel.GetComponent<RectTransform>();
            if (rt != null)
            {
                rt.anchorMin = Vector2.zero;
                rt.anchorMax = Vector2.one;
                rt.offsetMin = new Vector2(-100f, -100f); // 좌하단 100px 돌출
                rt.offsetMax = new Vector2(100f, 100f);   // 우상단 100px 돌출
            }
        }

        if (loadingText != null)
        {
            loadingText.text = defaultLoadingMessage;
        }

        if (loadingSlider != null)
        {
            loadingSlider.value = 0f;
        }

        if (progressCoroutine != null) StopCoroutine(progressCoroutine);
        progressCoroutine = StartCoroutine(AnimateProgressRoutine());
    }

    /// <summary>
    /// 맵 로딩 및 배치 완료 시 호출
    /// </summary>
    public void HideLoadingUI()
    {
        if (progressCoroutine != null)
        {
            StopCoroutine(progressCoroutine);
            progressCoroutine = null;
        }

        if (loadingSlider != null) loadingSlider.value = 1f;

        if (loadingPanel != null)
        {
            loadingPanel.SetActive(false);
        }
    }

    private IEnumerator AnimateProgressRoutine()
    {
        float timer = 0f;
        while (loadingPanel != null && loadingPanel.activeSelf)
        {
            timer += Time.unscaledDeltaTime;
            float simulatedProgress = Mathf.Clamp01(timer / 1.2f);

            if (loadingSlider != null)
            {
                loadingSlider.value = simulatedProgress;
            }

            if (loadingText != null)
            {
                int percent = Mathf.RoundToInt(simulatedProgress * 100f);
                loadingText.text = $"{defaultLoadingMessage} ({percent}%)";
            }

            yield return null;
        }
    }
}

using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 맵 전환(MapChanger) 진행 중일 때 화면 최상단에 Loading... 오버레이 UI 팝업창을 띄우고,
/// 로딩이 끝나면 감쪽같이 비활성화해주는 런타임 UI 로더 컨트롤러.
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
        // 씬 시작 시 로딩 패널은 끄기
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(false);
        }

        // MapChanger 이벤트 구독
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
    /// 맵 로딩 시작 시 호출 (OnMapChangeStarted 이벤트)
    /// </summary>
    public void ShowLoadingUI()
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(true);
        }

        if (loadingText != null)
        {
            loadingText.text = defaultLoadingMessage;
        }

        if (loadingSlider != null)
        {
            loadingSlider.value = 0f;
        }

        // 부드러운 프로그레스 연출 코루틴 시작
        if (progressCoroutine != null) StopCoroutine(progressCoroutine);
        progressCoroutine = StartCoroutine(AnimateProgressRoutine());
    }

    /// <summary>
    /// 맵 로딩 및 배치 완료 시 호출 (OnMapChangeCompleted 이벤트)
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
            float simulatedProgress = Mathf.Clamp01(timer / 1.5f); // 부드러운 연출

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

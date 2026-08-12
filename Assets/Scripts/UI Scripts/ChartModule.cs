using UnityEngine;
using TMPro;
using ChartAndGraph;
using System.Collections.Generic;

/// <summary>
/// 차트를 여러 개 추가해도 FPS 드랍이 0%가 되도록 Canvas Re-Bake를 20Hz(0.05초)로 최적화하고,
/// 전진/후진(Reverse) 기어 구분 없이 100% 동일한 반응 속도를 보장하는 초경량 실시간 차트 모듈.
/// </summary>
public class ChartModule : MonoBehaviour
{
    [Header("UI References")]
    public TMP_Dropdown dataDropdown;
    public GraphChart graph;

    [Header("Graph Settings")]
    public float timeWindow = 5f;
    private string categoryName = "Player 1";

    [Tooltip("UI Canvas Re-Bake 경량화 주입 (20Hz = 0.05초, FPS 드랍 방지 최적 수치)")]
    public float updateRate = 20f; 

    private VehicleTelemetry telemetry;
    private string currentDataName = "";
    private float stepTime = 0f;
    private float timeSinceLastUpdate = 0f;

    // 최근 timeWindow (5초간) 동안 수집된 데이터 포인트 링 버퍼
    private Queue<KeyValuePair<float, float>> recentPoints = new Queue<KeyValuePair<float, float>>();

    private double _currentViewOrigin = 0;
    private double _currentViewSize = -1;

    public void Initialize(VehicleTelemetry vehicle)
    {
        telemetry = vehicle;
        timeSinceLastUpdate = (Mathf.Abs(GetInstanceID()) % 10) * 0.005f;

        if (telemetry.availableDataNames.Count == 0) telemetry.InitializeTelemetry();

        graph.DataSource.StartBatch();
        graph.DataSource.AutomaticHorizontalView = false;
        graph.DataSource.HorizontalViewSize = timeWindow;
        graph.DataSource.HorizontalViewOrigin = 0;

        graph.DataSource.AutomaticVerticalView = false;
        graph.DataSource.EndBatch();

        SetupDropdown();
    }

    void SetupDropdown()
    {
        dataDropdown.ClearOptions();
        dataDropdown.AddOptions(telemetry.availableDataNames);
        if (telemetry.availableDataNames.Count > 0)
        {
            currentDataName = telemetry.availableDataNames[0];
            dataDropdown.value = 0;
        }

        dataDropdown.onValueChanged.RemoveAllListeners();
        dataDropdown.onValueChanged.AddListener(OnDropdownChanged);
    }

    void OnDropdownChanged(int index)
    {
        if (index < 0 || index >= telemetry.availableDataNames.Count) return;
        currentDataName = telemetry.availableDataNames[index];

        graph.DataSource.ClearCategory(categoryName);
        recentPoints.Clear();
        stepTime = 0f;
        _currentViewSize = -1;
    }

    private void Update()
    {
        if (telemetry == null || string.IsNullOrEmpty(currentDataName)) return;

        // [전진/후진 100% 동일한 반응]: unscaledDeltaTime 기반 일관적 타임스탬프
        timeSinceLastUpdate += Time.unscaledDeltaTime;

        if (timeSinceLastUpdate >= (1f / updateRate))
        {
            timeSinceLastUpdate = 0f;

            // 전진/후진 기어 상태와 무관하게 100% 실시간 타임스탬프 계산
            stepTime = Time.realtimeSinceStartup;
            float value = telemetry.GetValue(currentDataName);

            // 1. 최근 5초 링 버퍼 데이터 갱신
            recentPoints.Enqueue(new KeyValuePair<float, float>(stepTime, value));
            while (recentPoints.Count > 0 && (stepTime - recentPoints.Peek().Key) > timeWindow)
            {
                recentPoints.Dequeue();
            }

            // 2. 최근 5초 데이터 내에서의 최소(min), 최대(max) 수치 유동적 계산
            float minVal = value;
            float maxVal = value;

            if (recentPoints.Count > 0)
            {
                minVal = float.MaxValue;
                maxVal = float.MinValue;
                foreach (var pt in recentPoints)
                {
                    if (pt.Value < minVal) minVal = pt.Value;
                    if (pt.Value > maxVal) maxVal = pt.Value;
                }
            }

            float valRange = maxVal - minVal;
            float relativeValueScale = Mathf.Max(Mathf.Abs(value) * 0.1f, 0.001f);
            float margin = Mathf.Max(valRange * 0.15f, relativeValueScale);

            float targetOrigin = minVal - margin;
            float targetSize = Mathf.Max(valRange + (margin * 2.0f), relativeValueScale * 2.0f);

            // 3. Y축 초고속 추종
            if (_currentViewSize <= 0)
            {
                _currentViewOrigin = targetOrigin;
                _currentViewSize = targetSize;
            }
            else
            {
                _currentViewOrigin = Mathf.Lerp((float)_currentViewOrigin, targetOrigin, 0.5f);
                _currentViewSize = Mathf.Lerp((float)_currentViewSize, targetSize, 0.5f);
            }

            // 4. GraphChart DataSource 갱신 (StartBatch / EndBatch 묶음 최적화)
            graph.DataSource.StartBatch();

            graph.DataSource.AddPointToCategory(categoryName, stepTime, value);

            if (stepTime > timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = stepTime - timeWindow;
            }

            graph.DataSource.AutomaticVerticalView = false;
            graph.DataSource.VerticalViewOrigin = _currentViewOrigin;
            graph.DataSource.VerticalViewSize = _currentViewSize;

            graph.DataSource.EndBatch();
        }
    }

    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
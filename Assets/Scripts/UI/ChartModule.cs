using UnityEngine;
using TMPro;
using ChartAndGraph;
using System.Collections.Generic;

/// <summary>
/// min/max 범위의 5초 슬라이딩 윈도우 최상급 안정성을 100% 유지하며,
/// 20Hz 경량화 샘플링으로 초고속 프레임을 보장하는 초경량 실시간 차트 모듈.
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
    private float elapsedTime = 0f;
    private float timeSinceLastUpdate = 0f;

    // 최근 timeWindow (5초간) 동안 수집된 (time, value) 링 버퍼 큐
    private Queue<KeyValuePair<float, float>> recentPoints = new Queue<KeyValuePair<float, float>>();

    public void Initialize(VehicleTelemetry vehicle)
    {
        telemetry = vehicle;
        timeSinceLastUpdate = (Mathf.Abs(GetInstanceID()) % 10) * 0.005f;

        if (telemetry.availableDataNames.Count == 0) telemetry.InitializeTelemetry();

        graph.DataSource.StartBatch();
        graph.DataSource.AutomaticHorizontalView = false;
        graph.DataSource.HorizontalViewSize = timeWindow;
        graph.DataSource.HorizontalViewOrigin = 0;

        graph.DataSource.AutomaticVerticalView = true;
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

        ResetChartData();
    }

    public void ResetChartData()
    {
        if (graph != null && graph.DataSource != null)
        {
            graph.DataSource.ClearCategory(categoryName);
        }
        recentPoints.Clear();
        elapsedTime = 0f;
    }

    private void Update()
    {
        if (telemetry == null || string.IsNullOrEmpty(currentDataName)) return;

        float dt = Time.unscaledDeltaTime;
        timeSinceLastUpdate += dt;
        elapsedTime += dt;

        if (timeSinceLastUpdate >= (1f / updateRate))
        {
            timeSinceLastUpdate = 0f;

            float value = telemetry.GetValue(currentDataName);

            // 1. 최근 5초 링 버퍼 큐 갱신 (5초 경과 포인트 즉시 Dequeue)
            recentPoints.Enqueue(new KeyValuePair<float, float>(elapsedTime, value));
            while (recentPoints.Count > 0 && (elapsedTime - recentPoints.Peek().Key) > timeWindow)
            {
                recentPoints.Dequeue();
            }

            // 2. 5초 링 버퍼 실시간 데이터 포인트 차트 재등록
            graph.DataSource.StartBatch();

            graph.DataSource.ClearCategory(categoryName);
            foreach (var pt in recentPoints)
            {
                graph.DataSource.AddPointToCategory(categoryName, pt.Key, pt.Value);
            }

            if (elapsedTime > timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = elapsedTime - timeWindow;
            }

            graph.DataSource.AutomaticVerticalView = true;

            graph.DataSource.EndBatch();
        }
    }

    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
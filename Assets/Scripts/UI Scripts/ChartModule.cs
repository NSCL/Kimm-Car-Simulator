using UnityEngine;
using TMPro;
using ChartAndGraph;
using System.Collections.Generic;

public class ChartModule : MonoBehaviour
{
    [Header("UI References")]
    public TMP_Dropdown dataDropdown;
    public GraphChart graph;

    [Header("Graph Settings")]
    public float timeWindow = 5f;
    private string categoryName = "Player 1";
    public float updateRate = 10f; // 10Hz (0.1초)

    private VehicleTelemetry telemetry;
    private string currentDataName = "";
    private float stepTime = 0f;
    private float timeSinceLastUpdate = 0f;

    // ?? 패딩 갱신 횟수를 줄이기 위한 변수 추가
    private float lastAppliedPadding = -1f;

    private float timeSinceLastVerticalUpdate = 0f;

    public void Initialize(VehicleTelemetry vehicle)
    {
        telemetry = vehicle;

        // [원리 2: 프레임 분산 오프셋]
        timeSinceLastUpdate = (Mathf.Abs(GetInstanceID()) % 10) * 0.01f;

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

        graph.DataSource.ClearCategory(categoryName);
        stepTime = 0f;
        lastAppliedPadding = -1f;
    }

    private void Update()
    {
        if (telemetry == null || string.IsNullOrEmpty(currentDataName)) return;

        timeSinceLastUpdate += Time.deltaTime;
        timeSinceLastVerticalUpdate += Time.deltaTime;

        // 1. [10Hz 경량화 업데이트]: 데이터 포인트 추가 및 X축 슬라이딩 윈도우만 빠르게 갱신
        if (timeSinceLastUpdate >= (1f / updateRate))
        {
            timeSinceLastUpdate = 0f;

            stepTime = Time.timeSinceLevelLoad;
            float value = telemetry.GetValue(currentDataName);

            graph.DataSource.StartBatch();

            graph.DataSource.AddPointToCategory(categoryName, stepTime, value);

            if (stepTime > timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = stepTime - timeWindow;
            }

            // 2. [원리 3: Y축/패딩 연산 2Hz(0.5초) 주기 분리]
            // 매 10Hz 데이터마다 실행되던 Y축 자동범위 및 축 텍스트 재계산을 0.5초 주기로 분리하여 CPU 연산량 80% 절감
            if (timeSinceLastVerticalUpdate >= 0.5f)
            {
                timeSinceLastVerticalUpdate = 0f;

                float targetPadding = Mathf.Abs(value) * 0.2f;
                if (targetPadding < 0.5f) targetPadding = 0f;

                if (Mathf.Abs(targetPadding - lastAppliedPadding) > 1.0f)
                {
                    graph.DataSource.AutomaticVerticallViewGap = targetPadding;
                    lastAppliedPadding = targetPadding;
                }
            }

            graph.DataSource.EndBatch();
        }
    }

    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
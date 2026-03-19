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
    public float updateRate = 10f;

    private VehicleTelemetry telemetry;
    private string currentDataName = "";
    private float stepTime = 0f;
    private float timeSinceLastUpdate = 0f;

    public void Initialize(VehicleTelemetry vehicle)
    {
        telemetry = vehicle;
        if (telemetry.availableDataNames.Count == 0) telemetry.InitializeTelemetry();

        graph.DataSource.StartBatch();

        // X축 스크롤 세팅
        graph.DataSource.AutomaticHorizontalView = false;
        graph.DataSource.HorizontalViewSize = timeWindow;
        graph.DataSource.HorizontalViewOrigin = 0;

        // 에셋의 자동 스케일링 기능 켜기
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
        }

        dataDropdown.onValueChanged.AddListener(OnDropdownChanged);
    }

    void OnDropdownChanged(int index)
    {
        currentDataName = telemetry.availableDataNames[index];
        graph.DataSource.ClearCategory(categoryName);
        stepTime = 0f;
    }

    private void Update()
    {
        if (telemetry == null || string.IsNullOrEmpty(currentDataName)) return;

        stepTime += Time.deltaTime;
        timeSinceLastUpdate += Time.deltaTime;

        if (timeSinceLastUpdate >= (1f / updateRate))
        {
            timeSinceLastUpdate = 0f;
            float value = telemetry.GetValue(currentDataName);

            graph.DataSource.StartBatch();

            // 1. 차트에 점 추가
            graph.DataSource.AddPointToCategory(categoryName, stepTime, value);

            // 2. 시간이 지나면 X축을 왼쪽으로 밀어내기 (스크롤)
            if (stepTime > timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = stepTime - timeWindow;
            }

            // 3. 제안하신 '현재 값 기반의 Padding' 적용!
            // 현재 값의 20%를 여백으로 설정 (값이 커지면 여백도 자연스럽게 커짐)
            float padding = Mathf.Abs(value) * 0.2f;

            // 차가 완전히 정지해서 value가 0이 되었을 때, 최소한의 Y축 눈금 보장 (-0.5 ~ 0.5)
            if (padding < 0.5f) padding = 0f;

            // 에셋의 Gap 속성에 계산한 padding 값 주입 
            graph.DataSource.AutomaticVerticallViewGap = padding;

            graph.DataSource.EndBatch();
        }
    }

    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
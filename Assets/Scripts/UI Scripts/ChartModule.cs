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

    public void Initialize(VehicleTelemetry vehicle)
    {
        telemetry = vehicle;
        if (telemetry.availableDataNames.Count == 0) telemetry.InitializeTelemetry();

        graph.DataSource.StartBatch();

        graph.DataSource.AutomaticHorizontalView = false;
        graph.DataSource.HorizontalViewSize = timeWindow;
        graph.DataSource.HorizontalViewOrigin = 0;
        graph.DataSource.AutomaticVerticalView = true;

        // ?? 화면 밖으로 나간 과거 데이터 자동 삭제 설정 (메모리 및 프레임 최적화)
        // Asset 버전에 따라 MaxCapacity 설정이 있을 수 있습니다. (주석 해제 후 확인)
        // graph.DataSource.MaxCapacity = categoryName, 100; // 한 카테고리당 점 100개 유지

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
        lastAppliedPadding = -1f; // 카테고리 변경 시 패딩 리셋
    }

    private void Update()
    {
        if (telemetry == null || string.IsNullOrEmpty(currentDataName)) return;

        timeSinceLastUpdate += Time.deltaTime;

        if (timeSinceLastUpdate >= (1f / updateRate))
        {
            timeSinceLastUpdate = 0f;
            float value = telemetry.GetValue(currentDataName);
            stepTime = Time.timeSinceLevelLoad;

            graph.DataSource.StartBatch();

            // 1. 차트에 점 추가
            graph.DataSource.AddPointToCategory(categoryName, stepTime, value);

            // 2. 시간이 지나면 X축 스크롤 진행
            if (stepTime > timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = stepTime - timeWindow;

                // (선택) 에셋이 자동 삭제를 지원하지 않으면 여기서 수동으로 오래된 점 삭제
                // graph.DataSource.ClearCategory(categoryName, stepTime - timeWindow - 1f); 
            }

            // 3. [최적화] 조건부 Padding 업데이트
            float targetPadding = Mathf.Abs(value) * 0.2f;
            if (targetPadding < 0.5f) targetPadding = 0f;

            // ?? 무조건 갱신하지 않고, 패딩 값이 기존 대비 '일정 수치 이상' 변했을 때만 갱신!
            // (1.0f 이상 차이 날 때만 갱신. 이 수치는 데이터 스케일에 맞춰 조절하세요)
            if (Mathf.Abs(targetPadding - lastAppliedPadding) > 1.0f)
            {
                graph.DataSource.AutomaticVerticallViewGap = targetPadding;
                lastAppliedPadding = targetPadding;
            }

            graph.DataSource.EndBatch();
        }
    }

    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
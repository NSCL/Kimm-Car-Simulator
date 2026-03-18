using UnityEngine;
using TMPro;
using ChartAndGraph; // 구매하신 에셋 네임스페이스
using System.Collections.Generic;

public class ChartModule : MonoBehaviour
{
    [Header("UI References")]
    //public TextMeshProUGUI chartTitle;
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
        if(telemetry.availableDataNames.Count==0 ) telemetry.InitializeTelemetry();
        graph.DataSource.StartBatch();
        graph.DataSource.AutomaticHorizontalView = false;
        graph.DataSource.AutomaticVerticallView = true;
        graph.DataSource.HorizontalViewSize = timeWindow;
        graph.DataSource.HorizontalViewOrigin = 0;
        graph.DataSource.EndBatch();

        SetupDropdown();
    }

    void SetupDropdown()
    {
        dataDropdown.ClearOptions();
        dataDropdown.AddOptions(telemetry.availableDataNames);
        if(telemetry.availableDataNames.Count>0 )
        {
            currentDataName = telemetry.availableDataNames[0];
            //UpdateTitle();
        }

        dataDropdown.onValueChanged.AddListener(OnDropdownChanged);
    }

    void OnDropdownChanged(int index)
    {
        currentDataName = telemetry.availableDataNames[index];
        graph.DataSource.ClearCategory(categoryName);
        stepTime = 0f;
        //UpdateTitle();
    }

    //void UpdateTitle()
    //{
    //    if (chartTitle != null) chartTitle.text = currentDataName;
    //}

    private void Update()
    {
        if(telemetry==null || string.IsNullOrEmpty(currentDataName)) return;

        stepTime += Time.deltaTime;
        timeSinceLastUpdate += Time.deltaTime;

        if(timeSinceLastUpdate>=(1f/updateRate))
        {
            timeSinceLastUpdate = 0f;
            float value = telemetry.GetValue(currentDataName);

            graph.DataSource.StartBatch();
            graph.DataSource.AddPointToCategory(categoryName,stepTime,value);

            if(stepTime>timeWindow)
            {
                graph.DataSource.HorizontalViewOrigin = stepTime - timeWindow;
            }
            graph.DataSource.EndBatch();
        }

    }
    public void CloseChart()
    {
        Destroy(gameObject);
    }
}
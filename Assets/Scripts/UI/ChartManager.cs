using UnityEngine;

public class ChartManager : MonoBehaviour
{
    [Header("Data Source")]
    public VehicleTelemetry targetVehicle;

    [Header("UI References")]
    public GameObject chartPrefab;

    public Transform chartContainer;

    public void AddNewChart()
    {
        if (chartPrefab == null || targetVehicle == null || chartContainer == null)
        {
            Debug.LogWarning("ChartManager: No chartPrefab");
            return;
        }

        GameObject newChartObj = Instantiate(chartPrefab, chartContainer);
        ChartModule chartModule = newChartObj.GetComponent<ChartModule>();
        if (chartModule != null)
        {
            chartModule.Initialize(targetVehicle);
        }
    }

}

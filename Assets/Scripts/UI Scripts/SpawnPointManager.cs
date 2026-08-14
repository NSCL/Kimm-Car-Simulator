using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 스폰 지정 및 씬 상의 스폰 상태(hasValidSpawnPoint)를 관리하는 매니저.
/// </summary>
public class SpawnPointManager : MonoBehaviour
{
    public static SpawnPointManager Instance { get; private set; }

    [Header("Current Spawn Status")]
    public bool isPlacingSpawnPoint = false;
    public bool hasValidSpawnPoint = true;

    [Header("UI Notice & Lock Settings (Option)")]
    public GameObject noticeBannerPanel;
    public TextMeshProUGUI noticeBannerText;

    private Transform worldSpawnTransform;

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
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            hasValidSpawnPoint = true;
        }
    }

    public void OnSpawnPointButtonClick()
    {
        PrepareSpawnPointPlacementMode();
    }

    public void PrepareSpawnPointPlacementMode()
    {
        isPlacingSpawnPoint = true;

        if (noticeBannerPanel != null)
        {
            noticeBannerPanel.SetActive(true);
        }

        if (noticeBannerText != null)
        {
            noticeBannerText.text = "📌 [Notice] Please Left-Click on road ground to set Spawn Point! (Mouse Scroll: Rotate)";
        }

        RuntimeObjectPlacer placer = FindFirstObjectByType<RuntimeObjectPlacer>();
        if (placer != null)
        {
            placer.SelectSpawnPointMode();
        }
    }

    public void ApplySpawnPointToVehicle(Vector3 pos, Quaternion rot)
    {
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            if (vc.spawnPoint != null)
            {
                worldSpawnTransform = vc.spawnPoint;
            }
            else if (worldSpawnTransform == null)
            {
                GameObject spObj = GameObject.Find("3D_World_SpawnPoint_Marker");
                if (spObj == null) spObj = GameObject.Find("spawnPoint");
                if (spObj == null) spObj = GameObject.Find("SpawnPoint");
                if (spObj == null) spObj = new GameObject("3D_World_SpawnPoint_Marker");
                worldSpawnTransform = spObj.transform;
            }

            Vector3 safeSpawnPos = pos + Vector3.up * 0.2f;

            if (worldSpawnTransform != null)
            {
                worldSpawnTransform.position = safeSpawnPos;
                worldSpawnTransform.rotation = rot;
                vc.spawnPoint = worldSpawnTransform;
            }

            vc.ResetVehicle(safeSpawnPos, rot);
        }

        FreeFlyCamera flyCam = FindFirstObjectByType<FreeFlyCamera>();
        if (flyCam != null)
        {
            flyCam.AlignToVehiclePosition();
        }

        isPlacingSpawnPoint = false;
        hasValidSpawnPoint = true;

        if (noticeBannerPanel != null)
        {
            noticeBannerPanel.SetActive(false);
        }
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 마우스 클릭으로 새로운 스폰 위치를 배치하는 순간 차량 3D 위치 리셋뿐만 아니라
/// 에디트 모드 카메라(FreeFlyCamera) 시점까지 새로운 차체 바디 상공 및 Yaw 각도로 100% 함께 이동시킵니다.
/// </summary>
public class SpawnPointManager : MonoBehaviour
{
    public static SpawnPointManager Instance { get; private set; }

    [Header("Current Spawn Status")]
    public bool isPlacingSpawnPoint = false;
    public bool hasValidSpawnPoint = false;

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

    public void OnSpawnPointButtonClick()
    {
        PrepareSpawnPointPlacementMode();
    }

    public void PrepareSpawnPointPlacementMode()
    {
        hasValidSpawnPoint = false;
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

        Debug.Log("[SpawnPointManager] 차량 3D 고스트 스폰 모드 활성화 완료.");
    }

    /// <summary>
    /// 마우스 좌클릭 시 스폰 위치 이동 + 차량 리셋 + 에디트 카메라 위치/Yaw 100% 동시 이동!
    /// </summary>
    public void ApplySpawnPointToVehicle(Vector3 pos, Quaternion rot)
    {
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            // 1. 씬 내의 spawnPoint Transform 수색 및 자동 생성
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

            // 2. spawnPoint 위치와 회전 즉시 이동
            if (worldSpawnTransform != null)
            {
                worldSpawnTransform.position = safeSpawnPos;
                worldSpawnTransform.rotation = rot;
                vc.spawnPoint = worldSpawnTransform;
            }

            // 3. 차량 위치 및 물리 리셋
            vc.ResetVehicle(safeSpawnPos, rot);
            Debug.Log($"[SpawnPointManager] vc.spawnPoint 위치/회전 성공적으로 이동 완료! ➔ {safeSpawnPos}");
        }

        // 4. (요청 연동 수술) 에디트 카메라(FreeFlyCamera) 시점도 새로운 차체 바디 상공 및 Yaw 각도로 100% 함께 즉시 이동!
        FreeFlyCamera flyCam = FindFirstObjectByType<FreeFlyCamera>();
        if (flyCam != null)
        {
            flyCam.AlignToVehiclePosition();
            Debug.Log("[SpawnPointManager] 에디트 모드 카메라 시점도 새 스폰 위치 상공으로 100% 동시 이동 완료!");
        }

        isPlacingSpawnPoint = false;
        hasValidSpawnPoint = true;

        if (noticeBannerPanel != null)
        {
            noticeBannerPanel.SetActive(false);
        }

        Debug.Log($"[SpawnPointManager] spawnPoint 지정 완료! 차량 착지 및 카메라 이동 완료 ➔ {pos}");
    }
}

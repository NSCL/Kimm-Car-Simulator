using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

/// <summary>
/// 스폰 지정 및 씬 상의 스폰 상태(hasValidSpawnPoint)를 관리하는 매니저.
/// Auto Mode 일 때는 차량 스폰/리셋을 100% 완전 차단하고 오직 Goal Pose ('G' 깃발 마커) 배치 및 ROS2 전송만 집행합니다.
/// </summary>
public class SpawnPointManager : MonoBehaviour
{
    private static SpawnPointManager _instance;
    public static SpawnPointManager Instance => _instance;

    public Transform worldSpawnTransform;
    public bool isPlacingSpawnPoint = false;
    public bool hasValidSpawnPoint = true;

    [Header("Notice Banner UI")]
    public GameObject noticeBannerPanel;
    public TextMeshProUGUI noticeBannerText;

    private void Awake()
    {
        _instance = this;
    }

    private void Start()
    {
        CheckInitialSpawnPoint();
    }

    public void CheckInitialSpawnPoint()
    {
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null && vc.spawnPoint != null)
        {
            worldSpawnTransform = vc.spawnPoint;
            hasValidSpawnPoint = true;
        }
        else
        {
            GameObject spObj = GameObject.Find("3D_World_SpawnPoint_Marker");
            if (spObj == null) spObj = GameObject.Find("spawnPoint");
            if (spObj == null) spObj = GameObject.Find("SpawnPoint");

            if (spObj != null)
            {
                worldSpawnTransform = spObj.transform;
                hasValidSpawnPoint = true;
            }
            else
            {
                hasValidSpawnPoint = false;
            }
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

        AutonomousControlModeManager modeMgr = FindFirstObjectByType<AutonomousControlModeManager>();
        bool isAuto = (modeMgr != null && modeMgr.IsAutoMode);

        if (noticeBannerText != null)
        {
            noticeBannerText.text = isAuto 
                ? "🚩 [Auto Mode] Please Left-Click on road ground to set Goal Pose! (Mouse Scroll: Rotate)"
                : "📌 [Manual Mode] Please Left-Click on road ground to set Spawn Point! (Mouse Scroll: Rotate)";
        }

        RuntimeObjectPlacer placer = FindFirstObjectByType<RuntimeObjectPlacer>();
        if (placer != null)
        {
            placer.SelectSpawnPointMode();
        }
    }

    public void ApplySpawnPointToVehicle(Vector3 pos, Quaternion rot)
    {
        AutonomousControlModeManager modeMgr = FindFirstObjectByType<AutonomousControlModeManager>();
        bool isAuto = (modeMgr != null && modeMgr.IsAutoMode);

        // 🌟 Auto Mode 일 때는 차량 스폰/위치 리셋을 100% 완전 차단하고 Goal Pose 마커만 배치!
        if (isAuto)
        {
            KimmGoalPosePublisher goalPublisher = FindFirstObjectByType<KimmGoalPosePublisher>();
            if (goalPublisher != null)
            {
                goalPublisher.SetGoalPose(pos, rot);
            }
            else
            {
                Debug.LogWarning("⚠️ [SpawnPointManager] KimmGoalPosePublisher not found in scene!");
            }

            isPlacingSpawnPoint = false;
            if (noticeBannerPanel != null) noticeBannerPanel.SetActive(false);

            if (SimulatorManager.Instance != null)
            {
                SimulatorManager.Instance.SetSimulationMode();
            }
            return; // <-- 🛑 차량 ResetVehicle() 절대 도달 불가!
        }

        // 🎮 Manual Mode 일 때만 스폰 포인트 저장 및 차량위치 스폰 리셋!
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

        if (SimulatorManager.Instance != null)
        {
            SimulatorManager.Instance.SetSimulationMode();
        }
    }
}

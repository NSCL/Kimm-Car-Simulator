using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;

[System.Serializable]
public class MapInfo
{
    public string mapName;
    public string sceneName;
    public Sprite mapThumbnail;
    public Vector3 spawnPosition = new Vector3(0f, 0.5f, 0f);
    public Vector3 spawnRotation = Vector3.zero;
}

/// <summary>
/// 맵 Scene을 Additive 비동기 로드하고, 시놀로지 NAS 네트워크 드라이브 환경에서도 
/// 3D 메쉬 및 콜라이더 최적화가 100% 준비 완료될 때까지 로딩 패널을 정밀 동기화하는 매니저.
/// (빌드 최적화: 개발용 임시 로그 제거)
/// </summary>
public class MapChanger : MonoBehaviour
{
    public static MapChanger Instance { get; private set; }

    [Header("Vehicle Reference")]
    public Transform vehicleTransform;

    [Header("Available Maps")]
    public List<MapInfo> mapList = new List<MapInfo>();

    [Header("State")]
    public string activeMapSceneName;
    public int currentMapIndex = 0;
    public bool isTransitioning = false;

    public event System.Action OnMapChangeStarted;
    public event System.Action OnMapChangeCompleted;

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
        InitializeDefaultMaps();

        bool mapSceneLoaded = false;
        for (int i = 0; i < SceneManager.sceneCount; i++)
        {
            Scene s = SceneManager.GetSceneAt(i);
            if (IsMapScene(s.name))
            {
                mapSceneLoaded = true;
                activeMapSceneName = s.name;
                currentMapIndex = mapList.FindIndex(m => m.sceneName == s.name);
                break;
            }
        }

        if (!mapSceneLoaded && mapList.Count > 0)
        {
            ChangeMap(0);
        }
    }

    private void InitializeDefaultMaps()
    {
        if (mapList.Count == 0)
        {
            int sceneCount = SceneManager.sceneCountInBuildSettings;
            for (int i = 0; i < sceneCount; i++)
            {
                string scenePath = SceneUtility.GetScenePathByBuildIndex(i);
                string sceneName = System.IO.Path.GetFileNameWithoutExtension(scenePath);

                if (!string.IsNullOrEmpty(sceneName) && 
                    !sceneName.Equals("Main", System.StringComparison.OrdinalIgnoreCase) &&
                    !sceneName.Equals("Core", System.StringComparison.OrdinalIgnoreCase) &&
                    !sceneName.Equals("Origin", System.StringComparison.OrdinalIgnoreCase) &&
                    !sceneName.Equals("SampleScene", System.StringComparison.OrdinalIgnoreCase))
                {
                    mapList.Add(new MapInfo { mapName = sceneName, sceneName = sceneName, spawnPosition = new Vector3(0f, 0.5f, 0f) });
                }
            }

            if (mapList.Count == 0)
            {
                mapList.Add(new MapInfo { mapName = "K-City", sceneName = "K-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
                mapList.Add(new MapInfo { mapName = "M-City", sceneName = "M-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
                mapList.Add(new MapInfo { mapName = "Zalazone", sceneName = "Zalazone", spawnPosition = new Vector3(0f, 0.5f, 0f) });
            }
        }
    }

    public void ChangeToSelectedDropdownMap(TMP_Dropdown dropdown)
    {
        if (dropdown != null)
        {
            ChangeMap(dropdown.value);
        }
    }

    public void ChangeMap(int mapIndex)
    {
        if (isTransitioning) return;

        if (mapIndex < 0 || mapIndex >= mapList.Count)
        {
            Debug.LogError($"[MapChanger] 유효하지 않은 맵 인덱스: {mapIndex}");
            return;
        }

        StartCoroutine(SwitchMapRoutine(mapIndex));
    }

    private IEnumerator SwitchMapRoutine(int targetIndex)
    {
        isTransitioning = true;
        OnMapChangeStarted?.Invoke();
        if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(0.05f);

        MapInfo targetMap = mapList[targetIndex];

        // 1. 기존 로드된 Additive 맵 언로드
        for (int i = 0; i < SceneManager.sceneCount; i++)
        {
            Scene loadedScene = SceneManager.GetSceneAt(i);
            if (IsMapScene(loadedScene.name) && loadedScene.name != targetMap.sceneName)
            {
                if (loadedScene.isLoaded)
                {
                    AsyncOperation unloadOp = SceneManager.UnloadSceneAsync(loadedScene);
                    while (unloadOp != null && !unloadOp.isDone)
                    {
                        yield return null;
                    }
                }
            }
        }

        Resources.UnloadUnusedAssets();
        if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(0.15f);

        // 2. 신규 맵 비동기 Additive 로드
        AsyncOperation loadOp = SceneManager.LoadSceneAsync(targetMap.sceneName, LoadSceneMode.Additive);
        if (loadOp == null)
        {
            Debug.LogError($"[MapChanger] '{targetMap.sceneName}' 맵을 로드할 수 없습니다.");
            isTransitioning = false;
            yield break;
        }

        while (!loadOp.isDone)
        {
            float mappedProgress = Mathf.Lerp(0.15f, 0.85f, loadOp.progress / 0.9f);
            if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(mappedProgress);
            yield return null;
        }

        if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(0.85f);

        Scene newlyLoadedScene = SceneManager.GetSceneByName(targetMap.sceneName);
        if (newlyLoadedScene.IsValid())
        {
            SceneManager.SetActiveScene(newlyLoadedScene);
        }

        activeMapSceneName = targetMap.sceneName;
        currentMapIndex = targetIndex;

        yield return new WaitForEndOfFrame();
        yield return new WaitForSecondsRealtime(0.1f);
        if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(0.92f);

        RelocateVehicleExact(newlyLoadedScene, targetMap);

        if (MapPhysicsOptimizer.Instance != null)
        {
            MapPhysicsOptimizer.Instance.OptimizeCurrentMapImmediate();
        }

        yield return new WaitForEndOfFrame();
        if (LoadingPanelUI.Instance != null) LoadingPanelUI.Instance.SetProgress(1.0f);

        isTransitioning = false;
        OnMapChangeCompleted?.Invoke();

        if (EscMenuController.Instance != null && EscMenuController.Instance.isMenuOpen)
        {
            EscMenuController.Instance.OnClickResume();
        }
    }

    private void RelocateVehicleExact(Scene loadedMapScene, MapInfo targetMap)
    {
        if (vehicleTransform == null)
        {
            VehicleController vc = Object.FindAnyObjectByType<VehicleController>();
            if (vc != null) vehicleTransform = vc.transform;
        }

        if (vehicleTransform == null) return;

        Vector3 spawnPos = targetMap.spawnPosition;
        Quaternion spawnRot = Quaternion.Euler(targetMap.spawnRotation);

        Transform foundSpawnTransform = null;
        foreach (GameObject rootObj in loadedMapScene.GetRootGameObjects())
        {
            foundSpawnTransform = FindSpawnPointRecursively(rootObj.transform);
            if (foundSpawnTransform != null) break;
        }

        if (foundSpawnTransform != null)
        {
            spawnPos = foundSpawnTransform.position;
            spawnRot = foundSpawnTransform.rotation;
        }

        VehicleController vehicleCtrl = vehicleTransform.GetComponent<VehicleController>();
        if (vehicleCtrl != null)
        {
            vehicleCtrl.spawnPoint = foundSpawnTransform;
            vehicleCtrl.ResetVehicle(spawnPos, spawnRot);
        }
        else
        {
            vehicleTransform.position = spawnPos;
            vehicleTransform.rotation = spawnRot;
        }

        Rigidbody rb = vehicleTransform.GetComponent<Rigidbody>();
        if (rb != null)
        {
            rb.linearVelocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;
        }
    }

    private Transform FindSpawnPointRecursively(Transform parent)
    {
        if (parent == null) return null;

        string pName = parent.name.ToLower();
        if (pName.Contains("spawn point") || pName.Contains("spawnpoint") || pName.Contains("spawn_point"))
        {
            return parent;
        }

        foreach (Transform child in parent)
        {
            Transform found = FindSpawnPointRecursively(child);
            if (found != null) return found;
        }

        return null;
    }

    public bool IsMapScene(string sceneName)
    {
        if (string.IsNullOrEmpty(sceneName)) return false;
        foreach (var m in mapList)
        {
            if (m.sceneName.Equals(sceneName, System.StringComparison.OrdinalIgnoreCase)) return true;
        }
        return false;
    }
}

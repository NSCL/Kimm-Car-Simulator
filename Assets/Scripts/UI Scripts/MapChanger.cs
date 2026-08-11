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
    public Sprite mapThumbnail; // UI 썸네일 이미지 지원
    public Vector3 spawnPosition = new Vector3(0f, 0.5f, 0f);
    public Vector3 spawnRotation = Vector3.zero;
}

/// <summary>
/// 맵 Scene을 Additive 비동기 로드하고, 차량 위치를 해당 맵의 SpawnPoint로 이동시키는 매니저 클래스.
/// UI 드롭다운 및 '맵 이동' 버튼 클릭 시 맵 전환을 총괄합니다.
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
            Debug.Log($"[MapChanger] 초기 맵이 로드되지 않아 기본 맵({mapList[0].mapName})을 자동 로드합니다.");
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
                    mapList.Add(new MapInfo
                    {
                        mapName = sceneName,
                        sceneName = sceneName,
                        spawnPosition = new Vector3(0f, 0.5f, 0f),
                        spawnRotation = Vector3.zero
                    });
                }
            }

            if (mapList.Count == 0)
            {
                mapList.Add(new MapInfo { mapName = "K-City", sceneName = "K-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
                mapList.Add(new MapInfo { mapName = "M-City", sceneName = "M-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
            }
        }
    }

    /// <summary>
    /// TMP_Dropdown 참조를 받아 현재 드롭다운에서 선택된 항목의 맵으로 전환 (버튼 Click 용)
    /// </summary>
    public void ChangeToSelectedDropdownMap(TMP_Dropdown dropdown)
    {
        if (dropdown != null)
        {
            ChangeMap(dropdown.value);
        }
    }

    /// <summary>
    /// UI 드롭다운 인덱스를 받아 맵 전환 시작
    /// </summary>
    public void ChangeMap(int mapIndex)
    {
        if (isTransitioning)
        {
            Debug.LogWarning("[MapChanger] 이미 맵 전환이 진행 중입니다.");
            return;
        }

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

        MapInfo targetMap = mapList[targetIndex];
        Debug.Log($"[MapChanger] 맵 전환 시작: {targetMap.mapName} ({targetMap.sceneName})");

        // 1. 기존 로드된 Additive 맵 언로드
        for (int i = 0; i < SceneManager.sceneCount; i++)
        {
            Scene loadedScene = SceneManager.GetSceneAt(i);
            if (IsMapScene(loadedScene.name) && loadedScene.name != targetMap.sceneName)
            {
                if (loadedScene.isLoaded)
                {
                    Debug.Log($"[MapChanger] 기존 맵 언로드 중: {loadedScene.name}");
                    AsyncOperation unloadOp = SceneManager.UnloadSceneAsync(loadedScene);
                    while (unloadOp != null && !unloadOp.isDone)
                    {
                        yield return null;
                    }
                }
            }
        }

        // 2. 신규 맵 비동기 Additive 로드
        AsyncOperation loadOp = SceneManager.LoadSceneAsync(targetMap.sceneName, LoadSceneMode.Additive);
        if (loadOp == null)
        {
            Debug.LogError($"[MapChanger] '{targetMap.sceneName}' 맵을 로드할 수 없습니다. Build Settings를 확인하세요.");
            isTransitioning = false;
            yield break;
        }

        while (!loadOp.isDone)
        {
            yield return null;
        }

        yield return null;

        // 3. 로드된 맵을 Active Scene으로 지정
        Scene newlyLoadedScene = SceneManager.GetSceneByName(targetMap.sceneName);
        if (newlyLoadedScene.IsValid())
        {
            SceneManager.SetActiveScene(newlyLoadedScene);
        }

        activeMapSceneName = targetMap.sceneName;
        currentMapIndex = targetIndex;

        // 4. 차량을 신규 맵의 SpawnPoint 위치로 이동
        RelocateVehicle(newlyLoadedScene, targetMap);

        Debug.Log($"[MapChanger] 맵 전환 완료: {targetMap.mapName}");
        isTransitioning = false;
        OnMapChangeCompleted?.Invoke();
    }

    private void RelocateVehicle(Scene loadedMapScene, MapInfo targetMap)
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
        string normalizedName = parent.name.Replace(" ", "").Replace("_", "");

        if (normalizedName.Equals("SpawnPoint", System.StringComparison.OrdinalIgnoreCase) ||
            normalizedName.Equals("Spawn", System.StringComparison.OrdinalIgnoreCase) ||
            normalizedName.Equals("StartPoint", System.StringComparison.OrdinalIgnoreCase))
        {
            return parent;
        }

        try
        {
            if (string.Equals(parent.tag, "SpawnPoint", System.StringComparison.OrdinalIgnoreCase)) return parent;
        }
        catch { }

        foreach (Transform child in parent)
        {
            Transform res = FindSpawnPointRecursively(child);
            if (res != null) return res;
        }

        return null;
    }

    private bool IsMapScene(string sceneName)
    {
        return mapList.Exists(m => m.sceneName == sceneName);
    }
}

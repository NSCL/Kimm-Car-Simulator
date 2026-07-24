using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Events;

/// <summary>
/// 맵 정보 데이터 구조체
/// </summary>
[System.Serializable]
public class MapInfo
{
    [Tooltip("UI 드롭다운에 표시할 맵 이름")]
    public string mapName = "K-City";

    [Tooltip("유니티 Build Settings에 등록된 씬(Scene) 파일 이름")]
    public string sceneName = "K-City";

    [Tooltip("SpawnPoint 오브젝트가 없을 경우 사용할 기본 스폰 위치")]
    public Vector3 spawnPosition = Vector3.zero;

    [Tooltip("SpawnPoint 오브젝트가 없을 경우 사용할 기본 스폰 회전각 (Euler)")]
    public Vector3 spawnRotation = Vector3.zero;

    [Tooltip("맵 미리보기 이미지 (옵션)")]
    public Sprite mapThumbnail;
}

/// <summary>
/// 시뮬레이터 맵 비동기 전환 매니저 (Core Scene + Additive Map Scene 방식)
/// </summary>
public class MapChanger : MonoBehaviour
{
    public static MapChanger Instance;

    [Header("Map Configuration")]
    [Tooltip("전환 가능한 맵 목록")]
    public List<MapInfo> mapList = new List<MapInfo>();

    [Tooltip("현재 로드되어 있는 맵 인덱스")]
    public int currentMapIndex = 0;

    [Header("Vehicle Reference")]
    [Tooltip("맵 전환 시 이동시킬 차량 Transform")]
    public Transform vehicleTransform;

    [Header("Events")]
    [Tooltip("맵 전환 시작 시 실행할 이벤트 (UI 비활성화, 로딩창 켜기 등)")]
    public UnityEvent OnMapChangeStarted;

    [Tooltip("맵 전환 완료 시 실행할 이벤트 (UI 활성화, 로딩창 끄기 등)")]
    public UnityEvent OnMapChangeCompleted;

    private string activeMapSceneName = "";
    private bool isTransitioning = false;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        InitializeDefaultMaps();
    }

    private void Start()
    {
        // 차량 참조 자동 검색
        if (vehicleTransform == null)
        {
            VehicleController vc = Object.FindAnyObjectByType<VehicleController>();
            if (vc != null)
            {
                vehicleTransform = vc.transform;
            }
            else
            {
                GameObject vehicle = GameObject.FindWithTag("Player");
                if (vehicle != null) vehicleTransform = vehicle.transform;
            }
        }

        // 현재 씬에 로드되어 있는 맵 확인
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

        // 맵이 하나도 로드되어 있지 않다면 첫 번째 맵 자동 로드
        if (!mapSceneLoaded && mapList.Count > 0)
        {
            Debug.Log($"[MapChanger] 초기 맵이 씬에 없어 기본 맵({mapList[0].mapName})을 자동 로드합니다.");
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

                // Main, Core, SampleScene 등 프레임워크 전용 씬을 제외하고 Build Settings에 등록된 모든 맵 씬(Zalazone, K-City, M-City 등) 자동 등록
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

            // 만약 Build Settings에 맵이 없었던 예외 경우 대비 하드코딩 백업
            if (mapList.Count == 0)
            {
                mapList.Add(new MapInfo { mapName = "K-City", sceneName = "K-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
                mapList.Add(new MapInfo { mapName = "M-City", sceneName = "M-City", spawnPosition = new Vector3(0f, 0.5f, 0f) });
            }
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

        // 1. 기존 로드된 Additive 맵 씬 언로드
        for (int i = 0; i < SceneManager.sceneCount; i++)
        {
            Scene loadedScene = SceneManager.GetSceneAt(i);
            if (IsMapScene(loadedScene.name) && loadedScene.name != targetMap.sceneName)
            {
                if (loadedScene.isLoaded)
                {
                    Debug.Log($"[MapChanger] 기존 맵 씬 언로드 중: {loadedScene.name}");
                    AsyncOperation unloadOp = SceneManager.UnloadSceneAsync(loadedScene);
                    while (unloadOp != null && !unloadOp.isDone)
                    {
                        yield return null;
                    }
                }
            }
        }

        // 2. 신규 맵 씬 비동기 Additive 로드
        AsyncOperation loadOp = SceneManager.LoadSceneAsync(targetMap.sceneName, LoadSceneMode.Additive);
        if (loadOp == null)
        {
            Debug.LogError($"[MapChanger] '{targetMap.sceneName}' 씬을 로드할 수 없습니다. Build Settings를 확인하세요.");
            isTransitioning = false;
            yield break;
        }

        while (!loadOp.isDone)
        {
            yield return null;
        }

        yield return null; // Hierarchy 동기화 1프레임 대기

        // 3. 로드된 씬을 Active Scene으로 지정
        Scene newlyLoadedScene = SceneManager.GetSceneByName(targetMap.sceneName);
        if (newlyLoadedScene.IsValid())
        {
            SceneManager.SetActiveScene(newlyLoadedScene);
        }

        activeMapSceneName = targetMap.sceneName;
        currentMapIndex = targetIndex;

        // 4. 차량을 신규 맵 씬의 SpawnPoint 위치로 이동
        RelocateVehicle(newlyLoadedScene, targetMap);

        Debug.Log($"[MapChanger] 맵 전환 완결: {targetMap.mapName}");
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

        // 로드된 맵 씬 내부의 모든 오브젝트에서 SpawnPoint 탐색
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

        // 차량 위치 및 C++ FMU internal 위치 리셋
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

        // 유니티 Tag "SpawnPoint" 미등록 시 UnityException 발생 방지를 위한 안전한 비교
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

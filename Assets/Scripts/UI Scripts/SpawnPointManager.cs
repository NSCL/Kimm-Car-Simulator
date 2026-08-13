using UnityEngine;

/// <summary>
/// 씬 내의 spawnPoint Transform 오브젝트 위치를 관리하는 스폰 매니저.
/// </summary>
public class SpawnPointManager : MonoBehaviour
{
    public static SpawnPointManager Instance { get; private set; }

    [Header("Current Spawn Status")]
    public bool isPlacingSpawnPoint = false;

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

    /// <summary>
    /// 연구원님이 만드신 버튼 OnClick 에 연결할 1줄 함수!
    /// </summary>
    public void OnSpawnPointButtonClick()
    {
        RuntimeObjectPlacer placer = FindFirstObjectByType<RuntimeObjectPlacer>();
        if (placer != null)
        {
            placer.SelectSpawnPointMode();
        }
    }

    /// <summary>
    /// 마우스 클릭 지점으로 spawnPoint Transform 위치/회전을 이동시키고 씬 내에 없으면 자동 생성!
    /// </summary>
    public void ApplySpawnPointToVehicle(Vector3 pos, Quaternion rot)
    {
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            if (vc.spawnPoint == null)
            {
                GameObject spObj = GameObject.Find("spawnPoint");
                if (spObj == null) spObj = GameObject.Find("SpawnPoint");
                if (spObj == null) spObj = new GameObject("spawnPoint");
                vc.spawnPoint = spObj.transform;
            }

            if (vc.spawnPoint != null)
            {
                vc.spawnPoint.position = pos;
                vc.spawnPoint.rotation = rot;
            }
            vc.ResetVehicle(pos, rot);
        }
        isPlacingSpawnPoint = false;
        Debug.Log($"[SpawnPointManager] spawnPoint 위치가 성공적으로 이동/생성 되었습니다! ➔ {pos}");
    }
}

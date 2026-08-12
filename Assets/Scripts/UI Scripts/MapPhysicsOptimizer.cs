using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// 외부 커스텀 3D 맵 로드 시 맵 안의 모든 3D 메쉬 오브젝트에 1:1 정밀 MeshCollider를 부착하고,
/// 모든 콜라이더를 100% 항시 활성화(enabled = true) 상태로 안전하게 보장하는 오토 메셔 매니저.
/// </summary>
public class MapPhysicsOptimizer : MonoBehaviour
{
    public static MapPhysicsOptimizer Instance { get; private set; }

    [Header("Target Vehicle Reference")]
    public Transform vehicleTransform;

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
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeCompleted += OptimizeCurrentMap;
        }

        OptimizeCurrentMap();
    }

    private void OnDestroy()
    {
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeCompleted -= OptimizeCurrentMap;
        }
    }

    /// <summary>
    /// 로드된 맵 씬의 모든 3D 메쉬에 정밀 MeshCollider 부착 및 100% 항시 활성화 보장
    /// </summary>
    public void OptimizeCurrentMap()
    {
        if (vehicleTransform == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null) vehicleTransform = vc.transform;
        }

        Scene activeMapScene = SceneManager.GetActiveScene();
        GameObject[] rootObjects = activeMapScene.GetRootGameObjects();

        int attachedCount = 0;
        int totalMeshCount = 0;

        foreach (GameObject rootObj in rootObjects)
        {
            MeshRenderer[] renderers = rootObj.GetComponentsInChildren<MeshRenderer>(true);
            foreach (MeshRenderer mr in renderers)
            {
                if (mr == null || !mr.enabled) continue;
                MeshFilter mf = mr.GetComponent<MeshFilter>();
                if (mf == null || mf.sharedMesh == null) continue;

                GameObject obj = mr.gameObject;

                // 차량 본체 및 차체 하위 오브젝트 제외
                if (vehicleTransform != null && (obj.transform == vehicleTransform || obj.transform.IsChildOf(vehicleTransform)))
                {
                    continue;
                }

                if (obj.CompareTag("Player") || obj.layer == LayerMask.NameToLayer("UI") || obj.layer == LayerMask.NameToLayer("Ignore Raycast"))
                {
                    continue;
                }

                totalMeshCount++;

                // 이미 콜라이더가 존재하는지 확인 및 부착
                Collider col = obj.GetComponent<Collider>();
                if (col == null)
                {
                    MeshCollider mc = obj.AddComponent<MeshCollider>();
                    mc.sharedMesh = mf.sharedMesh;
                    mc.convex = false; // 오목한 표면 100% 외곽선 그대로 추종
                    col = mc;
                    attachedCount++;
                }

                // [핵심 보장]: 그 어떤 콜라이더도 절대로 끄지 않고 100% 항상 enabled = true 로 켜둠!
                col.enabled = true;
            }
        }

        Debug.Log($"[MapPhysicsOptimizer] 맵 3D 메쉬 정밀 스캔 완료: 총 {totalMeshCount}개 3D 메쉬 콜라이더 100% 상시 활성화 보장 (신규 정밀부착: {attachedCount}개)");
    }
}

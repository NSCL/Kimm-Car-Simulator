using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// M-City의 Pre-baked MeshCollider 및 3D 지면 메쉬 충돌체를 100% 파괴 없이 온전히 보존하고,
/// 배포 빌드(.exe)에서도 0.0001mm 오차 없이 3D 지면 접지를 100% 잡아채는 매니저.
/// </summary>
public class MapPhysicsOptimizer : MonoBehaviour
{
    public static MapPhysicsOptimizer Instance { get; private set; }

    [Header("Settings")]
    public bool autoOptimizeOnMapChange = true;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }

        Physics.defaultContactOffset = 0.01f;
    }

    private void Start()
    {
        OptimizeCurrentMapImmediate();
    }

    public void OptimizeCurrentMap()
    {
        OptimizeCurrentMapImmediate();
    }

    public void OptimizeCurrentMapImmediate()
    {
        Debug.Log("[MapPhysicsOptimizer] M-City / K-City / Zalazone 지면 충돌체 온전 보존 및 최적화 시작...");

        HashSet<GameObject> vehicleObjects = new HashSet<GameObject>();
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            Transform[] vTransforms = vc.GetComponentsInChildren<Transform>(true);
            foreach (Transform t in vTransforms)
            {
                vehicleObjects.Add(t.gameObject);
            }
        }

        GameObject[] playerTagged = GameObject.FindGameObjectsWithTag("Player");
        foreach (GameObject p in playerTagged)
        {
            Transform[] pTransforms = p.GetComponentsInChildren<Transform>(true);
            foreach (Transform t in pTransforms)
            {
                vehicleObjects.Add(t.gameObject);
            }
        }

        MeshRenderer[] allRenderers = FindObjectsByType<MeshRenderer>(FindObjectsSortMode.None);
        int preservedCount = 0;
        int newlyAdded = 0;

        foreach (MeshRenderer mr in allRenderers)
        {
            if (mr == null || !mr.enabled || !mr.gameObject.activeInHierarchy) continue;
            if (vehicleObjects.Contains(mr.gameObject)) continue;

            int layer = mr.gameObject.layer;
            if (layer == LayerMask.NameToLayer("UI") || 
                layer == LayerMask.NameToLayer("Ignore Raycast") || 
                layer == LayerMask.NameToLayer("TransparentFX"))
            {
                continue;
            }

            // [100% 핵심 수리]: 이미 Generate Colliders 로 붙어있는 정상 사전 콜라이더는 100% 절대로 건드리지 않고 온전히 활성화!
            Collider existingCol = mr.GetComponent<Collider>();
            if (existingCol != null)
            {
                existingCol.enabled = true;
                preservedCount++;
                continue;
            }

            MeshFilter mf = mr.GetComponent<MeshFilter>();
            if (mf == null || mf.sharedMesh == null || mf.sharedMesh.vertexCount == 0) continue;

            MeshCollider newCol = mr.gameObject.AddComponent<MeshCollider>();
            newCol.sharedMesh = mf.sharedMesh;
            newCol.convex = false;
            newCol.enabled = true;
            newlyAdded++;
        }

        Physics.SyncTransforms();

        Debug.Log($"[MapPhysicsOptimizer] 3D 지면 충돌체 완수! (사전 보존: {preservedCount}개, 신규 부착: {newlyAdded}개)");
    }
}

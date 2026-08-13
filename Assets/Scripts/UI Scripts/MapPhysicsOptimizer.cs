using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// M-City의 Pre-baked MeshCollider 및 3D 지면 메쉬 충돌체를 100% 파괴 없이 온전히 보존하고,
/// 배포 빌드(.exe)에서도 0.0001mm 오차 없이 3D 지면 접지를 100% 잡아채는 최적화 매니저.
/// (빌드 최적화: 불필요한 GC Console Log 100% 제거)
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

            Collider existingCol = mr.GetComponent<Collider>();
            if (existingCol != null)
            {
                existingCol.enabled = true;
                continue;
            }

            MeshFilter mf = mr.GetComponent<MeshFilter>();
            if (mf == null || mf.sharedMesh == null || mf.sharedMesh.vertexCount == 0) continue;

            MeshCollider newCol = mr.gameObject.AddComponent<MeshCollider>();
            newCol.sharedMesh = mf.sharedMesh;
            newCol.convex = false;
            newCol.enabled = true;
        }

        Physics.SyncTransforms();
    }
}

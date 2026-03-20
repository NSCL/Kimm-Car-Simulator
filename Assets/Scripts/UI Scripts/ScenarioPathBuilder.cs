using UnityEngine;
using UnityEngine.InputSystem;
using System.Collections.Generic;

public enum ActorState { Idle, Walk, Run}

[System.Serializable]
public class WaypointData
{
    public Vector3 position;
    public Quaternion rotation;
    public ActorState state;
}

public class ScenarioPathBuilder : MonoBehaviour
{
    [Header("Settings")]
    public GameObject waypointMarkerPrefab;
    public GameObject ghostPrefab;
    public LayerMask groundLayer;
    public float rotationSpeed = 10f;

    [Header("Current Path Data")]
    public List<WaypointData> currentPath = new List<WaypointData>();

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private float currentYRotation = 0f;
    private ActorState currentStateFromUI = ActorState.Idle;
    private bool isBuildingPath = false;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        if(SimulatorManager.Instance !=null)
        {
            controls = SimulatorManager.Instance.inputActions;
            controls.EditCamera.Place.performed += OnPlaceInput;

            if (SimulatorManager.Instance.editCamera != null)
            {
                editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
            }
        }
    }

    private void OnDestroy()
    {
        if (controls != null) controls.EditCamera.Place.performed -= OnPlaceInput;
    }

    public void StartBuildingPath()
    {
        isBuildingPath = true;
        currentPath.Clear();
        currentYRotation = 0f;

        if(currentGhost==null && ghostPrefab!=null)
        {
            currentGhost = Instantiate(ghostPrefab);
            foreach (var c in currentGhost.GetComponentsInChildren<Collider>())
            {
                c.enabled = false;
            }
        }
    }
    // Update is called once per frame
    void Update()
    {
        if(!isBuildingPath||SimulatorManager.Instance.IsSimulationActive())
        {
            if(currentGhost != null) currentGhost.SetActive(false);
            return;
        }

        UpdateGhostTransform();
    }

    void UpdateGhostTransform()
    {
        if (editCam == null || currentGhost == null) return;
        Vector2 mousePos = controls.EditCamera.MousePosition.ReadValue<Vector2>();
        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit hit;

        if(Physics.Raycast(ray, out hit,1000f,groundLayer))
        {
            currentGhost.SetActive(true);
            currentGhost.transform.position = hit.point;

            float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
            if (Mathf.Abs(scrollInput)>0.1f)
            {
                currentYRotation += scrollInput * rotationSpeed;
            }
            currentGhost.transform.rotation = Quaternion.Euler(0,currentYRotation,0);
        }
        else
        {
            currentGhost.SetActive(false);
        }
    }

    private void OnPlaceInput(InputAction.CallbackContext context)
    {
        if(!isBuildingPath ||SimulatorManager.Instance.IsSimulationActive()) { return; }
        if (currentGhost != null && currentGhost.activeSelf)
        {
            WaypointData newPoint = new WaypointData
            {
                position = currentGhost.transform.position,
                rotation = currentGhost.transform.rotation,
                state = currentStateFromUI
            };
            currentPath.Add(newPoint);

            if(waypointMarkerPrefab != null)
            {
                Instantiate(waypointMarkerPrefab,currentGhost.transform.position,currentGhost.transform.rotation);
            }
            Debug.Log($"웨이포인트 추가됨! 현재 총 {currentPath.Count}개의 점이 있습니다.");
        }
    }

    public void FinishBuildingPath()
    {
        isBuildingPath = false;
        if(currentGhost != null) Destroy(currentGhost);
        Debug.Log("경로 작성 완료! 저장된 점의 개수: " + currentPath.Count);
    }
}

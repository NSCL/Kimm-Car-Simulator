using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using TMPro;
using static SimulatorManager;

public enum ActorState { Idle, Walk, Run}

[System.Serializable]
public class WaypointData
{
    public Vector3 position;
    public Quaternion rotation;
    public ActorState state;
    public GameObject visualMarker;
}

/// <summary>
/// 시나리오 모드에서 보행자의 이동 경로(Waypoint)를 생성 및 편집하는 빌더 클래스.
/// LayerMask의 수동 설정 필요 없이 UI 및 Ignore Raycast를 제외한 모든 맵 지면 위에 경로를 생성합니다.
/// </summary>
public class ScenarioPathBuilder : MonoBehaviour
{
    [Header("Settings")]
    public GameObject waypointMarkerPrefab;
    public GameObject ghostPrefab;
    public GameObject pedestrianActorPrefab;
    public float rotationSpeed = 10f;
    public GameObject pathEditorPanel;
    public TMP_Dropdown stateDropdown;
    public LineRenderer pathLine;

    public TMP_InputField walkSpeedInput;
    public TMP_InputField runSpeedInput;

    [Header("Current Path Data")]
    public List<WaypointData> currentPath = new List<WaypointData>();

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private float currentYRotation = 0f;
    private ActorState currentStateFromUI = ActorState.Idle;
    private bool isBuildingPath = false;
    private bool isPointerOverUI = false;

    // 레이캐스트 감지 시 무시할 레이어 마스크 (Ignore Raycast 및 UI 제외)
    private static int _groundLayerMask = -1;

    void Start()
    {
        // [원리]: Ignore Raycast 및 UI 레이어를 제외한 레이어 마스크를 자동 비트 연산으로 초기화
        if (_groundLayerMask == -1)
        {
            int ignoreLayerBit = LayerMask.GetMask("Ignore Raycast", "UI");
            _groundLayerMask = ~ignoreLayerBit;
        }

        if (SimulatorManager.Instance != null)
        {
            controls = SimulatorManager.Instance.inputActions;
            controls.EditCamera.Place.performed += OnPlaceInput;
            SimulatorManager.Instance.OnModeChanged += HandleModeChanged;
            if (SimulatorManager.Instance.editCamera != null)
            {
                editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
            }
        }
    }

    private void OnDestroy()
    {
        if (controls != null) controls.EditCamera.Place.performed -= OnPlaceInput;
        if (SimulatorManager.Instance != null) SimulatorManager.Instance.OnModeChanged -= HandleModeChanged;
    }

    private void HandleModeChanged(SimulatorMode newMode)
    {
        if (newMode == SimulatorMode.Simulation)
        {
            HideWaypointMarkers();
        }
        else if (newMode == SimulatorMode.Edit)
        {
            ShowWaypointMarkers();
        }
    }

    public void StartBuildingPath()
    {
        if (pathLine != null) 
        { 
            pathLine.positionCount = 0;
            pathLine.loop = false;
        }
        if (walkSpeedInput != null) walkSpeedInput.text = "3";
        if (runSpeedInput != null) runSpeedInput.text = "5";
        isBuildingPath = true;
        currentPath.Clear();
        currentYRotation = 0f;
        if (pathEditorPanel != null) pathEditorPanel.SetActive(true);
        if (stateDropdown != null)
        {
            currentStateFromUI = (ActorState)stateDropdown.value;
        }
        if (currentGhost == null && ghostPrefab != null)
        {
            currentGhost = Instantiate(ghostPrefab);
            foreach (var c in currentGhost.GetComponentsInChildren<Collider>())
            {
                c.enabled = false;
            }
        }
    }

    void Update()
    {
        isPointerOverUI = EventSystem.current.IsPointerOverGameObject();
        if (!isBuildingPath || SimulatorManager.Instance.IsSimulationActive())
        {
            if (currentGhost != null) currentGhost.SetActive(false);
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

        if (Physics.Raycast(ray, out hit, 1000f, _groundLayerMask))
        {
            currentGhost.SetActive(true);
            currentGhost.transform.position = hit.point;

            float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
            if (Mathf.Abs(scrollInput) > 0.1f)
            {
                currentYRotation += scrollInput * rotationSpeed;
            }
            currentGhost.transform.rotation = Quaternion.Euler(0, currentYRotation, 0);
        }
        else
        {
            currentGhost.SetActive(false);
        }
    }

    private void OnPlaceInput(InputAction.CallbackContext context)
    {
        if (isPointerOverUI) return;
        if (!isBuildingPath || SimulatorManager.Instance.IsSimulationActive()) return;

        if (currentGhost != null && currentGhost.activeSelf)
        {
            GameObject newMarker = null;
            if (waypointMarkerPrefab != null)
            {
                newMarker = Instantiate(waypointMarkerPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
            }

            WaypointData newPoint = new WaypointData
            {
                position = currentGhost.transform.position,
                rotation = currentGhost.transform.rotation,
                state = currentStateFromUI,
                visualMarker = newMarker
            };

            currentPath.Add(newPoint);
            Debug.Log($"웨이포인트 추가됨. 현재 총 {currentPath.Count}개의 포인트가 존재합니다.");
            UpdatePathLine();
        }
    }

    public void FinishBuildingPath()
    {
        isBuildingPath = false;
        if (currentGhost != null) Destroy(currentGhost);
        Debug.Log("경로 생성 완료! 생성된 포인트 개수: " + currentPath.Count);
        if (pathEditorPanel != null) pathEditorPanel.SetActive(false);
        if (pathLine != null && currentPath.Count > 1)
        {
            pathLine.loop = true;
        }
        if (pedestrianActorPrefab != null && currentPath.Count > 0)
        {
            GameObject newActor = Instantiate(pedestrianActorPrefab);
            float wSpeed = 3f;
            float rSpeed = 5f;
            if (walkSpeedInput != null && float.TryParse(walkSpeedInput.text, out float parsedWalk)) wSpeed = parsedWalk;
            if (runSpeedInput != null && float.TryParse(runSpeedInput.text, out float parsedRun)) rSpeed = parsedRun;
            newActor.GetComponent<PedestrianActor>().InitializePath(currentPath, wSpeed, rSpeed);

            foreach (var point in currentPath)
            {
                if (point.visualMarker != null)
                {
                    newActor.GetComponent<PedestrianActor>().myMarkers.Add(point.visualMarker);
                }
            }
        }
    }

    public void CancelBuildingPath()
    {
        if (pathLine != null) pathLine.positionCount = 0;
        isBuildingPath = false;
        if (currentGhost != null) Destroy(currentGhost);
        if (pathEditorPanel != null) pathEditorPanel.SetActive(false);

        foreach (var point in currentPath)
        {
            if (point.visualMarker != null) Destroy(point.visualMarker);
        }
        currentPath.Clear();
    }

    public void HideWaypointMarkers()
    {
        if (pathLine != null) pathLine.enabled = false;
        foreach (var point in currentPath)
        {
            if (point.visualMarker != null)
            {
                point.visualMarker.SetActive(false);
            }
        }
    }

    public void ShowWaypointMarkers()
    {
        if (pathLine != null) pathLine.enabled = true;
        foreach (var point in currentPath)
        {
            if (point.visualMarker != null)
            {
                point.visualMarker.SetActive(true);
            }
        }
    }

    public void OnStateDropdownChanged(int index)
    {
        currentStateFromUI = (ActorState)index;
        Debug.Log(currentStateFromUI);
    }

    private void UpdatePathLine()
    {
        if (pathLine == null) return;

        pathLine.positionCount = currentPath.Count;
        for (int i = 0; i < currentPath.Count; i++)
        {
            pathLine.SetPosition(i, currentPath[i].position + Vector3.up * 0.1f);
        }
    }

    public void ClearAllPedestrians()
    {
        CancelBuildingPath();

        PedestrianActor[] allActors = FindObjectsByType<PedestrianActor>(FindObjectsSortMode.None);
        foreach (PedestrianActor actor in allActors)
        {
            Destroy(actor.gameObject);
        }

        Debug.Log($"총 {allActors.Length}명의 보행자를 제거하였습니다.");
    }
}

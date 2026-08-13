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
/// 보행자 기본 걷기 속도를 UI와 내부 파라미터 모두 2m/s로 100% 무조건 강제 세팅합니다.
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

    private static int _groundLayerMask = -1;

    void Start()
    {
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

        // [UI 100% 강제 세팅]: 인스펙터 텍스트에 3이 적혀있더라도 실행 시 무조건 2로 강제 세팅!
        if (walkSpeedInput != null)
        {
            walkSpeedInput.text = "2";
        }
        if (runSpeedInput != null && string.IsNullOrEmpty(runSpeedInput.text))
        {
            runSpeedInput.text = "5";
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

    void Update()
    {
        bool minimapHover = (MinimapController.Instance != null && MinimapController.Instance.IsMouseOverMinimap);
        isPointerOverUI = (EventSystem.current != null && EventSystem.current.IsPointerOverGameObject()) || minimapHover;

        if (!isBuildingPath || SimulatorManager.Instance.IsSimulationActive())
        {
            if (currentGhost != null) currentGhost.SetActive(false);
            return;
        }

        if (currentGhost == null && ghostPrefab != null)
        {
            CreateGhost();
        }

        if (currentGhost != null)
        {
            UpdateGhostTransform();
        }
    }

    public void StartBuildingPath()
    {
        CancelBuildingPath();
        isBuildingPath = true;
        if (pathEditorPanel != null) pathEditorPanel.SetActive(true);

        // 경로 작성 시작 시 걷기 속도 UI 2m/s 강제 동기화
        if (walkSpeedInput != null)
        {
            walkSpeedInput.text = "2";
        }
    }

    private void CreateGhost()
    {
        currentGhost = Instantiate(ghostPrefab);
        var colliders = currentGhost.GetComponentsInChildren<Collider>();
        foreach (var c in colliders) c.enabled = false;
        currentYRotation = 0f;
    }

    private void UpdateGhostTransform()
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
            GameObject newMarker = Instantiate(waypointMarkerPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
            WaypointData newPoint = new WaypointData
            {
                position = currentGhost.transform.position,
                rotation = currentGhost.transform.rotation,
                state = currentStateFromUI,
                visualMarker = newMarker
            };

            currentPath.Add(newPoint);
            UpdatePathLine();
        }
    }

    public void FinishBuildingPath()
    {
        isBuildingPath = false;
        if (currentGhost != null) Destroy(currentGhost);
        if (pathEditorPanel != null) pathEditorPanel.SetActive(false);
        if (pathLine != null && currentPath.Count > 1)
        {
            pathLine.loop = true;
        }
        if (pedestrianActorPrefab != null && currentPath.Count > 0)
        {
            GameObject newActor = Instantiate(pedestrianActorPrefab);
            float wSpeed = 2f;
            float rSpeed = 5f;
            if (walkSpeedInput != null && !string.IsNullOrEmpty(walkSpeedInput.text) && float.TryParse(walkSpeedInput.text, out float parsedWalk)) wSpeed = parsedWalk;
            if (runSpeedInput != null && !string.IsNullOrEmpty(runSpeedInput.text) && float.TryParse(runSpeedInput.text, out float parsedRun)) rSpeed = parsedRun;
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
    }
}

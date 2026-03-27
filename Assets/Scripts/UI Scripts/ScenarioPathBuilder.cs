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

public class ScenarioPathBuilder : MonoBehaviour
{
    [Header("Settings")]
    public GameObject waypointMarkerPrefab;
    public GameObject ghostPrefab;
    public GameObject pedestrianActorPrefab;
    public LayerMask groundLayer;
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
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        if(SimulatorManager.Instance !=null)
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
        SimulatorManager.Instance.OnModeChanged -= HandleModeChanged;
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
        if(runSpeedInput!=null) runSpeedInput.text = "10";
        isBuildingPath = true;
        currentPath.Clear();
        currentYRotation = 0f;
        if (pathEditorPanel != null) pathEditorPanel.SetActive(true);
        if (stateDropdown != null)
        {
            currentStateFromUI = (ActorState)stateDropdown.value;
        }
        if (currentGhost==null && ghostPrefab!=null)
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
        isPointerOverUI = EventSystem.current.IsPointerOverGameObject();
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
        // 1. UI 클릭 방어
        if (isPointerOverUI) return;

        // 2. 모드 확인
        if (!isBuildingPath || SimulatorManager.Instance.IsSimulationActive()) return;

        if (currentGhost != null && currentGhost.activeSelf)
        {
            // 3. (수정됨) 마커를 먼저 씬에 생성하고 변수에 담습니다!
            GameObject newMarker = null;
            if (waypointMarkerPrefab != null)
            {
                newMarker = Instantiate(waypointMarkerPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
            }

            // 4. 생성된 마커(newMarker)를 장부에 확실하게 기록합니다.
            WaypointData newPoint = new WaypointData
            {
                position = currentGhost.transform.position,
                rotation = currentGhost.transform.rotation,
                state = currentStateFromUI,
                visualMarker = newMarker // 이제 null이 아니라 실제 생성된 오브젝트가 들어갑니다!
            };

            currentPath.Add(newPoint);
            Debug.Log($"웨이포인트 추가됨! 현재 총 {currentPath.Count}개의 점이 있습니다.");
            UpdatePathLine();
        }
    }

    public void FinishBuildingPath()
    {
        isBuildingPath = false;
        if(currentGhost != null) Destroy(currentGhost);
        Debug.Log("경로 작성 완료! 저장된 점의 개수: " + currentPath.Count);
        if(pathEditorPanel != null) pathEditorPanel.SetActive(false);
        if (pathLine != null && currentPath.Count > 1)
        {
            pathLine.loop = true;
        }
        if (pedestrianActorPrefab!= null && currentPath.Count>0)
        {
            GameObject newActor = Instantiate(pedestrianActorPrefab);
            float wSpeed = 3f;
            float rSpeed = 5f;
            if (walkSpeedInput != null && float.TryParse(walkSpeedInput.text, out float parsedWalk)) wSpeed = parsedWalk;
            if (runSpeedInput != null && float.TryParse(runSpeedInput.text, out float parsedRun)) rSpeed = parsedRun;
            newActor.GetComponent<PedestrianActor>().InitializePath(currentPath, wSpeed, rSpeed);

            foreach(var point in currentPath)
            {
                if(point.visualMarker != null)
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

        // 화면에 찍어둔 마커들을 싹 다 지워버립니다.
        foreach (var point in currentPath)
        {
            if (point.visualMarker != null) Destroy(point.visualMarker);
        }
        currentPath.Clear(); // 장부도 초기화
    }
    // 시뮬레이션 모드 진입 시 호출할 함수
    public void HideWaypointMarkers()
    {
        if (pathLine != null) pathLine.enabled = false;
        foreach (var point in currentPath)
        {
            if (point.visualMarker != null)
            {
                point.visualMarker.SetActive(false); // 눈에서만 숨김! 데이터는 살아있음.
            }
        }
    }

    // (옵션) 다시 Edit Mode로 돌아왔을 때 보이게 하려면
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

        pathLine.positionCount = currentPath.Count; // 점의 개수만큼 선의 꺾임 포인트를 만듦
        for (int i = 0; i < currentPath.Count; i++)
        {
            // 선이 땅에 파묻히지 않게 Y축으로 살짝(0.1f) 띄워줍니다!
            pathLine.SetPosition(i, currentPath[i].position + Vector3.up * 0.1f);
        }
    }
    public void ClearAllPedestrians()
    {
        // 1. 혹시 경로를 그리고 있던 중이라면 취소
        CancelBuildingPath();

        // 2. 씬에 있는 모든 보행자(PedestrianActor)를 찾아서 싹 지웁니다.
        PedestrianActor[] allActors = FindObjectsByType<PedestrianActor>(FindObjectsSortMode.None);
        foreach (PedestrianActor actor in allActors)
        {
            Destroy(actor.gameObject);
        }

        Debug.Log($"총 {allActors.Length}명의 보행자를 삭제했습니다.");
    }
}

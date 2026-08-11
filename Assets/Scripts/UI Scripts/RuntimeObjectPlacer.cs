using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;

/// <summary>
/// 에디트 모드에서 장애물/오브젝트를 마우스 커서 위치에 실시간으로 배치(Placement)하는 컨트롤러 클래스.
/// LayerMask의 수동 설정 필요 없이 UI 및 Ignore Raycast를 제외한 모든 지면에 오브젝트 배치를 수행합니다.
/// </summary>
public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    public float rotationSpeed = 10f;

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private Quaternion initialRotation;
    private float currentYRotation = 0f;
    private bool isPointerOverUI = false;

    // 레이캐스트 감지 시 무시할 레이어 마스크 (Ignore Raycast 및 UI 제외)
    private static int _placementLayerMask = -1;

    void Start()
    {
        // [원리]: Ignore Raycast 및 UI 레이어를 제외한 레이어 마스크를 자동 비트 연산으로 초기화
        if (_placementLayerMask == -1)
        {
            int ignoreLayerBit = LayerMask.GetMask("Ignore Raycast", "UI");
            _placementLayerMask = ~ignoreLayerBit;
        }

        if (SimulatorManager.Instance != null)
        {
            controls = SimulatorManager.Instance.inputActions;
            controls.EditCamera.Place.performed += OnPlaceInput;
            controls.EditCamera.Remove.performed += OnRemoveInput;
            if (SimulatorManager.Instance.editCamera != null)
                editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
        }
    }

    void OnDestroy()
    {
        if (controls != null) controls.EditCamera.Place.performed -= OnPlaceInput;
        if (controls != null) controls.EditCamera.Remove.performed -= OnRemoveInput;
    }

    void Update()
    {
        bool minimapHover = (MinimapController.Instance != null && MinimapController.Instance.IsMouseOverMinimap);
        isPointerOverUI = (EventSystem.current != null && EventSystem.current.IsPointerOverGameObject()) || minimapHover;
        
        if (SimulatorManager.Instance.IsSimulationActive())
        {
            if (currentGhost != null) currentGhost.SetActive(false);
            return;
        }

        if (currentGhost == null && objectPrefab != null)
        {
            CreateGhost();
        }

        if (currentGhost != null)
        {
            UpdateGhostTransform();
        }
    }

    private void OnRemoveInput(InputAction.CallbackContext context)
    {
        if (SimulatorManager.Instance.IsSimulationActive()) return;
        Vector2 mousePos = controls.EditCamera.MousePosition.ReadValue<Vector2>();
        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit[] hits = Physics.RaycastAll(ray, 1000f);
        foreach (RaycastHit hit in hits)
        {
            if (hit.collider.CompareTag("SpawnedObject"))
            {
                Destroy(hit.collider.gameObject);
                Debug.Log($"삭제 완료: {hit.collider.name}");
                return;
            }
        }
    }

    public void SelectItem(GameObject newPrefab)
    {
        if (currentGhost != null) Destroy(currentGhost);
        objectPrefab = newPrefab;
        currentYRotation = 0f;
    }

    void CreateGhost()
    {
        currentGhost = Instantiate(objectPrefab);
        initialRotation = currentGhost.transform.rotation;

        var colliders = currentGhost.GetComponentsInChildren<Collider>();
        foreach (var c in colliders) c.enabled = false;

        currentYRotation = 0f;
    }

    void UpdateGhostTransform()
    {
        if (editCam == null) return;

        Vector2 mousePos = controls.EditCamera.MousePosition.ReadValue<Vector2>();
        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit, 1000f, _placementLayerMask))
        {
            currentGhost.SetActive(true);
            currentGhost.transform.position = hit.point;

            float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
            if (Mathf.Abs(scrollInput) > 0.1f)
            {
                currentYRotation += scrollInput * rotationSpeed;
            }

            Quaternion addedRotation = Quaternion.Euler(0, currentYRotation, 0);
            currentGhost.transform.rotation = addedRotation * initialRotation;
        }
        else
        {
            currentGhost.SetActive(false);
        }
    }

    private void OnPlaceInput(InputAction.CallbackContext context)
    {
        if (isPointerOverUI) return;
        if (SimulatorManager.Instance.IsSimulationActive()) return;

        if (currentGhost != null && currentGhost.activeSelf)
        {
            Instantiate(objectPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
        }
    }
}
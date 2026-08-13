using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;

/// <summary>
/// 에디트 모드에서 과속방지턱, 드럼통 등 오브젝트 3D 오리지널 쿼터니언 축(initialRotation)을 100% 온전히 보존하여
/// 과속방지턱 피치가 90도 서 버리는 버그를 소탕하고, 차량 정면 각도 및 5도 정밀 스크롤 회전을 지원하는 매니저.
/// </summary>
public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    
    [Tooltip("마우스 휠 스크롤 1회당 회전할 세분화 각도 (기본: 5도 정밀 세분화)")]
    public float rotationStepAngle = 5f;

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private Quaternion initialRotation;
    private float currentYRotation = 0f;
    private bool isPointerOverUI = false;

    private static int _placementLayerMask = -1;

    void Start()
    {
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
        RaycastHit hit;
        if (Physics.Raycast(ray, out hit, 1000f))
        {
            if (hit.collider.CompareTag("SpawnedObject"))
            {
                Destroy(hit.collider.gameObject);
            }
        }
    }

    public void SelectItem(GameObject newPrefab)
    {
        if (currentGhost != null) Destroy(currentGhost);
        objectPrefab = newPrefab;
        ResetYRotationToVehicleYaw();
    }

    private void ResetYRotationToVehicleYaw()
    {
        float vehicleYaw = 0f;
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            vehicleYaw = vc.transform.eulerAngles.y;
        }
        currentYRotation = vehicleYaw;
    }

    void CreateGhost()
    {
        currentGhost = Instantiate(objectPrefab);
        initialRotation = currentGhost.transform.rotation;

        var colliders = currentGhost.GetComponentsInChildren<Collider>();
        foreach (var c in colliders) c.enabled = false;

        ResetYRotationToVehicleYaw();
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

            // 마우스 휠 스크롤 1틱당 5도 단위 정밀 Y축 회전
            float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
            if (Mathf.Abs(scrollInput) > 0.05f)
            {
                float direction = Mathf.Sign(scrollInput);
                currentYRotation += direction * rotationStepAngle;
                currentYRotation = (currentYRotation % 360f + 360f) % 360f;
            }

            // [버그 완치 100%]: 오리지널 3D 프리팹 축(initialRotation)과 Y축 회전의 정밀 합성으로 피치 90도 꺾임 원천 차단!
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
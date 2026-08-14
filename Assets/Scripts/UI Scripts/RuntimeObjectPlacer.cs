using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;

/// <summary>
/// 프리팹 자체의 원본 3D 회전값(initialRotation)을 100% 보존하면서
/// 차량의 Heading Yaw 회전각 및 휠 5도 정밀 회전을 결합하는 장애물 매니저.
/// </summary>
public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    
    [Tooltip("마우스 휠 스크롤 1회당 회전할 세분화 각도 (기본: 5도 정밀 세분화)")]
    public float rotationStepAngle = 5f;

    private GameObject currentGhost;
    private GameObject vehicleGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private Quaternion initialRotation = Quaternion.identity;
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

    public void ClearGhost()
    {
        if (currentGhost != null)
        {
            Destroy(currentGhost);
            currentGhost = null;
        }
        if (vehicleGhost != null)
        {
            Destroy(vehicleGhost);
            vehicleGhost = null;
        }
        objectPrefab = null;
    }

    public void SelectSpawnPointMode()
    {
        ClearGhost();
        if (SpawnPointManager.Instance != null)
        {
            SpawnPointManager.Instance.isPlacingSpawnPoint = true;
        }
        ResetYRotationToVehicleYaw();
    }

    void Update()
    {
        bool minimapHover = (MinimapController.Instance != null && MinimapController.Instance.IsMouseOverMinimap);
        isPointerOverUI = (EventSystem.current != null && EventSystem.current.IsPointerOverGameObject()) || minimapHover;
        
        if (SimulatorManager.Instance != null && SimulatorManager.Instance.IsSimulationActive())
        {
            if (currentGhost != null) currentGhost.SetActive(false);
            if (vehicleGhost != null) vehicleGhost.SetActive(false);
            return;
        }

        if (SpawnPointManager.Instance != null && SpawnPointManager.Instance.isPlacingSpawnPoint)
        {
            if (currentGhost != null) currentGhost.SetActive(false);
            UpdateVehicleGhostTransform();
            return;
        }
        else
        {
            if (vehicleGhost != null) vehicleGhost.SetActive(false);
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

    private Vector2 GetExactMouseScreenPosition()
    {
        if (Mouse.current != null)
        {
            return Mouse.current.position.ReadValue();
        }
        return Input.mousePosition;
    }

    private void UpdateVehicleGhostTransform()
    {
        if (vehicleGhost == null)
        {
            VehicleController vc = FindFirstObjectByType<VehicleController>();
            if (vc != null)
            {
                vehicleGhost = Instantiate(vc.gameObject);
                vehicleGhost.name = "VehicleGhostPreview";
                
                Camera[] cameras = vehicleGhost.GetComponentsInChildren<Camera>(true);
                foreach (var c in cameras) Destroy(c.gameObject);

                AudioListener[] listeners = vehicleGhost.GetComponentsInChildren<AudioListener>(true);
                foreach (var al in listeners) Destroy(al);

                MonoBehaviour[] scripts = vehicleGhost.GetComponentsInChildren<MonoBehaviour>(true);
                foreach (var s in scripts) Destroy(s);

                Collider[] colliders = vehicleGhost.GetComponentsInChildren<Collider>(true);
                foreach (var c in colliders) c.enabled = false;

                Rigidbody rb = vehicleGhost.GetComponent<Rigidbody>();
                if (rb != null) Destroy(rb);

                ResetYRotationToVehicleYaw();
            }
        }

        if (vehicleGhost == null) return;

        if (editCam == null && SimulatorManager.Instance != null && SimulatorManager.Instance.editCamera != null)
            editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
        if (editCam == null) return;

        Vector2 mousePos = GetExactMouseScreenPosition();
        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit, 1000f, _placementLayerMask))
        {
            vehicleGhost.SetActive(true);
            
            if (!isPointerOverUI)
            {
                float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
                if (Mathf.Abs(scrollInput) > 0.05f)
                {
                    float direction = Mathf.Sign(scrollInput);
                    currentYRotation += direction * rotationStepAngle;
                    currentYRotation = (currentYRotation % 360f + 360f) % 360f;
                }
            }

            vehicleGhost.transform.rotation = Quaternion.Euler(0, currentYRotation, 0);
            vehicleGhost.transform.position = hit.point;
        }
        else
        {
            vehicleGhost.SetActive(false);
        }
    }

    private void OnRemoveInput(InputAction.CallbackContext context)
    {
        if (SimulatorManager.Instance != null && SimulatorManager.Instance.IsSimulationActive()) return;
        Vector2 mousePos = GetExactMouseScreenPosition();
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
        if (SpawnPointManager.Instance != null) SpawnPointManager.Instance.isPlacingSpawnPoint = false;
        if (currentGhost != null) Destroy(currentGhost);
        if (vehicleGhost != null) Destroy(vehicleGhost);
        objectPrefab = newPrefab;
        
        if (objectPrefab != null)
        {
            initialRotation = objectPrefab.transform.rotation;
        }
        
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
        if (objectPrefab == null) return;

        currentGhost = Instantiate(objectPrefab);
        initialRotation = objectPrefab.transform.rotation;

        var colliders = currentGhost.GetComponentsInChildren<Collider>();
        foreach (var c in colliders) c.enabled = false;

        ResetYRotationToVehicleYaw();
    }

    void UpdateGhostTransform()
    {
        if (editCam == null)
        {
            if (SimulatorManager.Instance != null && SimulatorManager.Instance.editCamera != null)
                editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
            if (editCam == null) return;
        }

        Vector2 mousePos = GetExactMouseScreenPosition();
        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit, 1000f, _placementLayerMask))
        {
            currentGhost.SetActive(true);
            currentGhost.transform.position = hit.point;

            if (!isPointerOverUI)
            {
                float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
                if (Mathf.Abs(scrollInput) > 0.05f)
                {
                    float direction = Mathf.Sign(scrollInput);
                    currentYRotation += direction * rotationStepAngle;
                    currentYRotation = (currentYRotation % 360f + 360f) % 360f;
                }
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
        if (SimulatorManager.Instance != null && SimulatorManager.Instance.IsSimulationActive()) return;

        if (SpawnPointManager.Instance != null && SpawnPointManager.Instance.isPlacingSpawnPoint)
        {
            if (vehicleGhost != null && vehicleGhost.activeSelf)
            {
                Vector3 spawnPos = vehicleGhost.transform.position;
                Quaternion spawnRot = vehicleGhost.transform.rotation;

                SpawnPointManager.Instance.ApplySpawnPointToVehicle(spawnPos, spawnRot);

                Destroy(vehicleGhost);
                vehicleGhost = null;
            }
            return;
        }

        if (currentGhost != null && currentGhost.activeSelf && objectPrefab != null)
        {
            Instantiate(objectPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
        }
    }
}
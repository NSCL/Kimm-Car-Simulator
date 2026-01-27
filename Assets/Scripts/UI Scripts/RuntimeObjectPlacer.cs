using UnityEngine;
using UnityEngine.InputSystem;
public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    public Material ghostMaterial;

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        if (SimulatorManager.Instance != null)
        {
            controls = SimulatorManager.Instance.inputActions;
            controls.EditCamera.Place.performed += OnPlaceInput;
        }

        if (SimulatorManager.Instance != null && SimulatorManager.Instance.editCamera!=null) 
        {
            editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
        }
    }

    void OnDestroy()
    {
        if(controls != null)
        {
            controls.EditCamera.Place.performed -= OnPlaceInput;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(SimulatorManager.Instance.IsSimulationActive())
        {
            if(currentGhost  != null) currentGhost.SetActive(false);
            return;
        }

        if (currentGhost == null && objectPrefab != null)
        {
            currentGhost = Instantiate(objectPrefab);

            var colliders = currentGhost.GetComponentsInChildren<Collider>();
            foreach (var c in colliders) c.enabled = false;
        }

        if(currentGhost != null)
        {
            currentGhost.SetActive(true);
            MoveGhostToMouse();
        }
    }

    void MoveGhostToMouse()
    {
        if (editCam == null) return;
        Vector2 mousePos = controls.EditCamera.MousePosition.ReadValue<Vector2>();

        Ray ray = editCam.ScreenPointToRay(mousePos);
        RaycastHit hit;

        if(Physics.Raycast(ray, out hit,1000f))
        {
            currentGhost.transform.position = hit.point;
        }
    }

    private void OnPlaceInput(InputAction.CallbackContext context)
    {
        if (SimulatorManager.Instance.IsSimulationActive()) return;
        if (currentGhost != null && currentGhost.activeSelf)
        {
            Instantiate(objectPrefab,currentGhost.transform.position,currentGhost.transform.rotation);
            Debug.Log("오브젝트 설치 완료!");
        }
    }
}

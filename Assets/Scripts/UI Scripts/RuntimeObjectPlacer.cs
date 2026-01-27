using UnityEngine;
using UnityEngine.InputSystem;

public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    public LayerMask placementLayer;
    public float rotationSpeed = 10f; // 속도 조금 올림

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;

    // ? 추가된 변수 1: 프리팹의 원래 회전값을 저장할 변수
    private Quaternion initialRotation;
    private float currentYRotation = 0f;

    void Start()
    {
        if (SimulatorManager.Instance != null)
        {
            controls = SimulatorManager.Instance.inputActions;
            controls.EditCamera.Place.performed += OnPlaceInput;

            if (SimulatorManager.Instance.editCamera != null)
                editCam = SimulatorManager.Instance.editCamera.GetComponent<Camera>();
        }
    }

    void OnDestroy()
    {
        if (controls != null) controls.EditCamera.Place.performed -= OnPlaceInput;
    }

    void Update()
    {
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

    void CreateGhost()
    {
        currentGhost = Instantiate(objectPrefab);

        // ? 수정 1: 생성되자마자 프리팹 본연의 회전값을 기억함!
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

        if (Physics.Raycast(ray, out hit, 1000f, placementLayer))
        {
            currentGhost.SetActive(true);
            currentGhost.transform.position = hit.point;

            // 휠 입력 받기
            float scrollInput = controls.EditCamera.RotateItem.ReadValue<float>();
            if (Mathf.Abs(scrollInput) > 0.1f)
            {
                currentYRotation += scrollInput * rotationSpeed; // * Time.deltaTime 빼는 게 반응이 더 즉각적임
            }

            // ? 수정 2: "내 휠 회전(Y축)" * "원래 프리팹 회전"
            // 쿼터니언 곱셈은 순서가 중요합니다. (추가 회전 * 원래 회전)
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
        if (SimulatorManager.Instance.IsSimulationActive()) return;

        if (currentGhost != null && currentGhost.activeSelf)
        {
            Instantiate(objectPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
        }
    }
}
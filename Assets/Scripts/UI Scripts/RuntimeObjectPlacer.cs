using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
public class RuntimeObjectPlacer : MonoBehaviour
{
    [Header("Settings")]
    public GameObject objectPrefab;
    public LayerMask placementLayer;
    public float rotationSpeed = 10f; // 속도 조금 올림

    private GameObject currentGhost;
    private SimulatorControls controls;
    private Camera editCam;
    private Quaternion initialRotation;
    private float currentYRotation = 0f;
    private bool isPointerOverUI = false;

    void Start()
    {
        // [원리]: 인스펙터에서 placementLayer가 설정되지 않은 경우(0/Nothing),
        // "Ignore Raycast" 및 "UI" 레이어를 제외한 모든 레이어(~ (Ignore Raycast | UI))를 
        // 감지 마스크로 설정하여 맵 지형의 레이어 설정(Default, Ground, Map 등)에 관계없이 마우스 배치가 동작하도록 합니다.
        if (placementLayer.value == 0)
        {
            int ignoreLayerBit = LayerMask.GetMask("Ignore Raycast", "UI");
            placementLayer = ~ignoreLayerBit;
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
            // 만약 태그가 "SpawnedObject"인 녀석을 발견하면?
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
        if(isPointerOverUI) return;

        if (SimulatorManager.Instance.IsSimulationActive()) return;

        if (currentGhost != null && currentGhost.activeSelf)
        {
            Instantiate(objectPrefab, currentGhost.transform.position, currentGhost.transform.rotation);
        }
    }

}
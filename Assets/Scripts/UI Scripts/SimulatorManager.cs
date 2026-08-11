using System;
using UnityEngine;
using UnityEngine.InputSystem;

public class SimulatorManager : MonoBehaviour
{
    public static SimulatorManager Instance;
    
    public SimulatorControls inputActions;
    public enum SimulatorMode
    {
        Simulation, // 주행모드
        Edit        // 편집모드
    }

    [Header("Status")]
    public SimulatorMode currentMode = SimulatorMode.Simulation;

    [Header("References")]
    public GameObject vehicleCamera; // 운전자 3인칭 카메라
    public GameObject editCamera;    // 맵 편집 탑뷰 프리카메라
    public VehicleController vehicleController; // 차량 제어 스크립트
    public GameObject editModeUIGroup;

    public event Action<SimulatorMode> OnModeChanged;

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);

        inputActions = new SimulatorControls();
    }

    void OnEnable()
    {
        inputActions.Enable();
        inputActions.Global.ToggleMode.performed += OnToggleModeInput;
    }

    void OnDisable()
    {
        inputActions.Global.ToggleMode.performed -= OnToggleModeInput;
        inputActions.Disable();
    }

    void Start()
    {
        ApplyMode(currentMode);
    }

    private void OnToggleModeInput(InputAction.CallbackContext context)
    {
        ToggleMode();
    }

    public void ToggleMode()
    {
        if (currentMode == SimulatorMode.Simulation)
            currentMode = SimulatorMode.Edit;
        else
            currentMode = SimulatorMode.Simulation;

        ApplyMode(currentMode);
        OnModeChanged?.Invoke(currentMode);
    }

    void ApplyMode(SimulatorMode mode)
    {
        if(mode == SimulatorMode.Simulation)
        {
            Debug.Log("Mode: Simulation");

            // 1. 카메라 및 UI 전환
            if (vehicleCamera) vehicleCamera.SetActive(true);
            if (editCamera) editCamera.SetActive(false);
            if (editModeUIGroup != null) editModeUIGroup.SetActive(false);
            
            // 2. 차량 조작 허용
            if (vehicleController) vehicleController.enabled = true;

            // 3. 주행 모드 시 시뮬레이션 시간 재개 (TimeScale = 1)
            Time.timeScale = 1.0f;
        }
        else
        {
            Debug.Log("Mode: Edit");

            // 1. 카메라 및 UI 전환
            if (vehicleCamera) vehicleCamera.SetActive(false);
            if (editCamera) editCamera.SetActive(true);
            
            Vector3 carPos = vehicleController != null ? vehicleController.transform.position : (vehicleCamera != null ? vehicleCamera.transform.position : Vector3.zero);
            float carYaw = vehicleController != null ? vehicleController.transform.eulerAngles.y : (vehicleCamera != null ? vehicleCamera.transform.eulerAngles.y : 0f);

            editCamera.transform.position = carPos + Vector3.up * 50f;
            editCamera.transform.rotation = Quaternion.Euler(90f, carYaw, 0f);
            if (editModeUIGroup != null) editModeUIGroup.SetActive(true);

            // 2. 차량 조작 차단
            if (vehicleController) vehicleController.enabled = false;

            // 3. 맵 에디트 모드 시 시뮬레이션 시간 정지 (TimeScale = 0)
            Time.timeScale = 0.0f;
        }
    }

    public bool IsSimulationActive()
    {
        return currentMode == SimulatorMode.Simulation;
    }
}

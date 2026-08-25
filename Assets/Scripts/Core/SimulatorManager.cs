using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// 시뮬레이터 모드(주행 모드 / 에디트 모드) 전환을 관장하는 매니저.
/// </summary>
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

    public bool IsSimulationActive()
    {
        return currentMode == SimulatorMode.Simulation;
    }

    [Header("References")]
    public GameObject vehicleCamera;
    public GameObject editCamera;
    public VehicleController vehicleController;
    public GameObject editModeUIGroup;

    public event Action<SimulatorMode> OnModeChanged;

    private void Awake()
    {
        Application.runInBackground = true; // rviz2, 터미널 등 타 창 클릭 시에도 백그라운드 100% 멈춤없이 연속 실행!
        if (Instance == null) Instance = this;
        else Destroy(gameObject);

        inputActions = new SimulatorControls();
    }

    void OnEnable()
    {
        if (inputActions != null)
        {
            inputActions.Enable();
            inputActions.Global.ToggleMode.performed += OnToggleModeInput;
        }
    }

    void OnDisable()
    {
        if (inputActions != null)
        {
            inputActions.Global.ToggleMode.performed -= OnToggleModeInput;
            inputActions.Disable();
        }
    }

    private void Start()
    {
        if (TelemetryUIController.Instance == null)
        {
            gameObject.AddComponent<TelemetryUIController>();
        }
        ApplyMode(currentMode);
    }

    private void OnToggleModeInput(InputAction.CallbackContext context)
    {
        ToggleMode();
    }

    public void ToggleMode()
    {
        currentMode = (currentMode == SimulatorMode.Simulation) ? SimulatorMode.Edit : SimulatorMode.Simulation;
        ApplyMode(currentMode);
    }

    public void SetEditMode()
    {
        currentMode = SimulatorMode.Edit;
        ApplyMode(currentMode);
    }

    public void SetSimulationMode()
    {
        currentMode = SimulatorMode.Simulation;
        ApplyMode(currentMode);
    }

    public void ApplyMode(SimulatorMode mode)
    {
        currentMode = mode;
        bool isSim = (mode == SimulatorMode.Simulation);

        Time.timeScale = isSim ? 1f : 0f;

        if (vehicleCamera != null) vehicleCamera.SetActive(isSim);
        if (editCamera != null)
        {
            editCamera.SetActive(!isSim);
            if (!isSim)
            {
                FreeFlyCamera flyCam = editCamera.GetComponent<FreeFlyCamera>();
                if (flyCam != null) flyCam.AlignToVehiclePosition();
            }
        }

        if (editModeUIGroup != null) editModeUIGroup.SetActive(!isSim);

        if (!isSim)
        {
            RuntimeObjectPlacer placer = FindFirstObjectByType<RuntimeObjectPlacer>();
            if (placer != null)
            {
                placer.SelectSpawnPointMode();
            }
        }

        OnModeChanged?.Invoke(mode);
    }
}

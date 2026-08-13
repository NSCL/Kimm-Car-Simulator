using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// Unity New Input System Package의 .inputactions 에셋(SimulatorControls)을 100% 정석대로 활용하고,
/// 에디트 모드(Edit Mode) 전환 시 시뮬레이션 물리 시간을 100% 일시정지(Time.timeScale = 0)시키는 매니저.
/// (빌드 최적화: 디버그 로그 제거)
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

    private void ApplyMode(SimulatorMode mode)
    {
        bool isSim = (mode == SimulatorMode.Simulation);

        Time.timeScale = isSim ? 1f : 0f;

        if (vehicleCamera != null) vehicleCamera.SetActive(isSim);
        if (editCamera != null) editCamera.SetActive(!isSim);

        if (editModeUIGroup != null) editModeUIGroup.SetActive(!isSim);

        OnModeChanged?.Invoke(mode);
    }
}

using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// Unity New Input System Package의 .inputactions 에셋(SimulatorControls)을 100% 정석대로 활용하고,
/// 에디트 모드(Edit Mode) 전환 시 시뮬레이션 물리 시간을 100% 일시정지(Time.timeScale = 0)시키는 매니저.
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
    }

    private void ApplyMode(SimulatorMode mode)
    {
        bool isEdit = (mode == SimulatorMode.Edit);

        // [핵심 해결 100%]: 에디트 모드 진입 시 물리 시간 100% 일시정지(Time.timeScale = 0), 주행 모드 복귀 시 정상 재개(Time.timeScale = 1.0)
        Time.timeScale = isEdit ? 0f : 1.0f;

        if (vehicleCamera != null) vehicleCamera.SetActive(!isEdit);
        if (editCamera != null) editCamera.SetActive(isEdit);

        if (vehicleController != null)
        {
            var inputManager = vehicleController.GetComponent<VehicleInputManager>();
            if (inputManager != null)
            {
                inputManager.SetInputActive(!isEdit);
            }
        }

        if (editModeUIGroup != null)
        {
            editModeUIGroup.SetActive(isEdit);
        }

        Cursor.lockState = isEdit ? CursorLockMode.None : CursorLockMode.None;
        Cursor.visible = true;

        OnModeChanged?.Invoke(mode);

        Debug.Log($"[SimulatorManager] 모드 변환 완료: {mode} (Time.timeScale: {Time.timeScale})");
    }
}

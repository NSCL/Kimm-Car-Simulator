using UnityEngine;
using UnityEngine.InputSystem;

public class SimulatorManager : MonoBehaviour
{
    public static SimulatorManager Instance;
    
    public SimulatorControls inputActions;
    public enum SimulatorMode
    {
        Simulation, //주행모드
        Edit //편집모드
    }

    [Header("Status")]
    public SimulatorMode currentMode = SimulatorMode.Simulation;

    [Header("References")]
    public GameObject vehicleCamera; //운전석 3인칭 카메라
    public GameObject editCamera; //항공뷰/편집용 프리캠
    public VehicleController vehicleController; //차량 제어 스크립트

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

    // Start is called once before the first execution of Update after the MonoBehaviour is created
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

    void ApplyMode(SimulatorMode mode)
    {
        if(mode == SimulatorMode.Simulation)
        {
            Debug.Log("Mode: Simulation");

            //1. 카메라 전환
            if (vehicleCamera) vehicleCamera.SetActive(true);
            if(editCamera) editCamera.SetActive(false);

            //차량 조작 허용
            if (vehicleController) vehicleController.enabled = true;
        }
        else
        {
            Debug.Log("Mode: Edit");

            //1. 카메라 전환
            if(vehicleCamera) vehicleCamera.SetActive(false);
            if(editCamera) editCamera.SetActive(true);

            //2. 차량 조작 차단
            if(vehicleController) vehicleController.enabled = false;
        }
    }

    public bool IsSimulationActive()
    {
        return currentMode == SimulatorMode.Simulation;
    }
}

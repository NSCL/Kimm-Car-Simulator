using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Kimm;

/// <summary>
/// KIMM 전용 커스텀 제어 메시지(CarControlCmdMsg: accel, steering, brake, gear)를 
/// ROS2 자율주행 노드로부터 100% 1:1 직통 수신하여 차량(VehicleInputManager)에 대입해 주는 수신기.
/// (부호 축 100% 정밀 보정)
/// </summary>
[DisallowMultipleComponent]
public class ROSCmdVelSubscriber : MonoBehaviour
{
    [Header("ROS2 Topic Settings")]
    public string cmdTopicName = "/kimm/car_cmd";

    [Header("Current Direct Received Values")]
    public float accel = 0.0f;
    public float steering = 0.0f;
    public float brake = 0.0f;
    public int gear = 1; // 1: Drive, -1: Reverse, 0: Neutral

    private ROSConnection _rosConnection;
    private VehicleInputManager _inputManager;
    private AutonomousControlModeManager _modeManager;

    private void Start()
    {
        _inputManager = FindFirstObjectByType<VehicleInputManager>();
        _modeManager = FindFirstObjectByType<AutonomousControlModeManager>();

        _rosConnection = ROSConnection.GetOrCreateInstance();
        _rosConnection.Subscribe<CarControlCmdMsg>(cmdTopicName, OnCarCmdReceived);
    }

    /// <summary>
    /// ROS2 자율주행 노드가 쏘아주는 Custom 메시지 1:1 직통 수신
    /// </summary>
    private void OnCarCmdReceived(CarControlCmdMsg msg)
    {
        accel = msg.accel;
        steering = msg.steering;
        brake = msg.brake;
        gear = msg.gear;
    }

    private void Update()
    {
        // 🌟 Auto Mode 일 때만 ROS2 커스텀 수치를 차량 VehicleInputManager 에 1:1 직통 대입!
        if (_modeManager != null && _modeManager.IsAutoMode)
        {
            if (_inputManager != null)
            {
                _inputManager.Accel = Mathf.Clamp01(accel);
                // 🧭 조향 방향 정밀 보정 (+: 좌회전 -> 유니티 핸들 -1.0)
                _inputManager.Steering = -Mathf.Clamp(steering, -1.0f, 1.0f);
                _inputManager.Brake = Mathf.Clamp01(brake);

                if (gear > 0)
                {
                    _inputManager.ShiftGear(VehicleInputManager.GearState.Drive);
                }
                else if (gear < 0)
                {
                    _inputManager.ShiftGear(VehicleInputManager.GearState.Reverse);
                }
                else
                {
                    _inputManager.ShiftGear(VehicleInputManager.GearState.Park);
                }
            }
        }
    }
}

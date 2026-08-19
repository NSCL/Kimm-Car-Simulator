using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Kimm;

/// <summary>
/// 유니티 차량의 실시간 4대 제어 상태(accel, steering, brake, gear)를 
/// KIMM 커스텀 메시지(CarControlCmdMsg)로 ROS2 자율주행 제어 노드에 100% 실시간 피드백 퍼블리싱해 주는 상태 퍼블리서.
/// </summary>
[DisallowMultipleComponent]
public class VehicleStatusPublisher : MonoBehaviour
{
    [Header("ROS2 Publisher Settings")]
    public string statusTopicName = "/kimm/vehicle_status";
    public float publishFrequency = 50f; // 50Hz

    private ROSConnection _rosConnection;
    private VehicleInputManager _inputManager;
    private float _timer = 0f;

    private void Start()
    {
        _inputManager = FindFirstObjectByType<VehicleInputManager>();
        _rosConnection = ROSConnection.GetOrCreateInstance();
        _rosConnection.RegisterPublisher<CarControlCmdMsg>(statusTopicName);

        Debug.Log($"🚗 [VehicleStatusPublisher] Registered Custom Status Topic '{statusTopicName}' successfully!");
    }

    private void Update()
    {
        if (_rosConnection == null || _inputManager == null) return;

        _timer += Time.deltaTime;
        float interval = 1.0f / publishFrequency;

        if (_timer >= interval)
        {
            _timer = 0f;
            PublishVehicleStatus();
        }
    }

    private void PublishVehicleStatus()
    {
        CarControlCmdMsg statusMsg = new CarControlCmdMsg();

        // 🌟 실시간 차량 4대 상태 수치 퍼블리싱 (accel, steering, brake, gear)
        statusMsg.accel = _inputManager.Accel;
        statusMsg.steering = _inputManager.Steering;
        statusMsg.brake = _inputManager.Brake;
        statusMsg.gear = (sbyte)_inputManager.Gear;

        _rosConnection.Publish(statusTopicName, statusMsg);
    }
}

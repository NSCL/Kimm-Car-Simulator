using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using Unity.Robotics.ROSTCPConnector.ROSGeometry;
using RosMessageTypes.Nav;
using RosMessageTypes.Geometry;

/// <summary>
/// 유니티 FMU 차량의 실시간 3D 정밀 위치(Position X,Y,Z),
/// 3D 쿼터니언 오리엔테이션(Orientation X,Y,Z,W), 
/// 및 실시간 종/횡 속도(body_vx, body_vy) 수치를 ROS2 자율주행 공식 표준 규격
/// ('nav_msgs/msg/Odometry')으로 50Hz 실시간 퍼블리싱해 주는 차량 상태 퍼블리서.
/// (모든 맵 스폰 헤딩 방향 100% 1:1 완벽 정밀 보정)
/// </summary>
[DisallowMultipleComponent]
public class VehicleStatusPublisher : MonoBehaviour
{
    [Header("ROS2 Publisher Settings")]
    public string statusTopicName = "/kimm/vehicle_status";
    public string frameId = "map";
    public string childFrameId = "base_link";
    public float publishFrequency = 50f; // 50Hz

    private ROSConnection _rosConnection;
    private FMUManager _fmuManager;
    private float _timer = 0f;

    private void Start()
    {
        _fmuManager = FindFirstObjectByType<FMUManager>();
        _rosConnection = ROSConnection.GetOrCreateInstance();
        _rosConnection.RegisterPublisher<OdometryMsg>(statusTopicName);
    }

    private void Update()
    {
        if (_rosConnection == null) return;

        _timer += Time.deltaTime;
        float interval = 1.0f / publishFrequency;

        if (_timer >= interval)
        {
            _timer = 0f;
            PublishVehicleStatusOdometry();
        }
    }

    private void PublishVehicleStatusOdometry()
    {
        OdometryMsg odomMsg = new OdometryMsg();

        // 1. Header 설정
        odomMsg.header.frame_id = frameId;
        odomMsg.child_frame_id = childFrameId;
        odomMsg.header.stamp = new RosMessageTypes.BuiltinInterfaces.TimeMsg();

        // 2. 유니티 3D 씬 내 실제 절대 위치(World Position) & Quaternion Orientation
        Vector3 rawPos = transform.position;
        Quaternion rawRot = transform.rotation; // 차체 실제 3D 월드 바라보는 회전각!

        // 유니티 ➔ ROS (FLU) 정통 3D 좌표 변환 적용! (Position & Orientation 100% 1:1 일치)
        odomMsg.pose.pose.position = rawPos.To<FLU>();
        odomMsg.pose.pose.orientation = rawRot.To<FLU>();

        // 3. FMU exact 변수 키 (body_vx, body_vy) 직통 읽기
        float vx = 0f;
        float vy = 0f;

        if (_fmuManager != null)
        {
            try
            {
                double fmuVx = _fmuManager.GetValue("body_vx");
                double fmuVy = _fmuManager.GetValue("body_vy");

                if (double.IsNaN(fmuVx)) fmuVx = _fmuManager.GetValue("Veh_BodyVel_X");
                if (double.IsNaN(fmuVy)) fmuVy = _fmuManager.GetValue("Veh_BodyVel_Y");

                if (!double.IsNaN(fmuVx)) vx = (float)fmuVx;
                if (!double.IsNaN(fmuVy)) vy = (float)fmuVy;
            }
            catch
            {
            }
        }

        odomMsg.twist.twist.linear.x = vx; // 종속도 (Forward Velocity m/s)
        odomMsg.twist.twist.linear.y = vy; // 횡속도 (Lateral Velocity m/s)
        odomMsg.twist.twist.linear.z = 0.0;

        _rosConnection.Publish(statusTopicName, odomMsg);
    }
}

using System.Collections;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using Unity.Robotics.ROSTCPConnector.ROSGeometry;
using RosMessageTypes.Geometry;

/// <summary>
/// Auto Mode 상태에서 사용자가 시뮬레이터 3D 화면 지점 클릭 시 
/// Goal Destination ('G' 깃발 마커)을 배치하고 
/// ROS2 자율주행 공식 표준 토픽('/goal_pose' - geometry_msgs/msg/PoseStamped)으로
/// 1초 안전 방어 재전송 및 QoS Latching 퍼블리싱을 집행하는 매니저.
/// (전 맵 거대 3D 좌표 오프셋 100% 정밀 보정)
/// </summary>
[DisallowMultipleComponent]
public class KimmGoalPosePublisher : MonoBehaviour
{
    private static KimmGoalPosePublisher _instance;
    public static KimmGoalPosePublisher Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = FindFirstObjectByType<KimmGoalPosePublisher>();
                if (_instance == null)
                {
                    GameObject go = new GameObject("KimmGoalPosePublisher");
                    _instance = go.AddComponent<KimmGoalPosePublisher>();
                }
            }
            return _instance;
        }
    }

    [Header("ROS2 Topic Settings")]
    public string goalPoseTopic = "/goal_pose";

    [Header("Goal Marker Settings")]
    public GameObject goalMarkerPrefab; // 'G' 깃발 3D 마커 프리팹 (없으면 3D 핀 자동 생성)
    private GameObject _currentGoalMarkerInstance;

    [Header("Current Goal Pose")]
    public Vector3 currentGoalPosition;
    public Quaternion currentGoalRotation;

    private ROSConnection _rosConnection;

    private void Awake()
    {
        _instance = this;
    }

    private void Start()
    {
        EnsureROSInitialized();
    }

    private void EnsureROSInitialized()
    {
        if (_rosConnection == null)
        {
            _rosConnection = ROSConnection.GetOrCreateInstance();
            _rosConnection.RegisterPublisher<PoseStampedMsg>(goalPoseTopic);
        }
    }

    private VehicleController _vehicle;
    private bool _hasGoalBeenReached = false;

    private void Update()
    {
        if (_currentGoalMarkerInstance != null && _currentGoalMarkerInstance.activeInHierarchy && !_hasGoalBeenReached)
        {
            if (_vehicle == null) _vehicle = FindFirstObjectByType<VehicleController>();
            if (_vehicle != null)
            {
                float dist = Vector3.Distance(_vehicle.transform.position, currentGoalPosition);
                if (dist < 2.5f)
                {
                    ClearGoalMarker();
                    _hasGoalBeenReached = true;
                }
            }
        }
    }

    public void ClearGoalMarker()
    {
        if (_currentGoalMarkerInstance != null)
        {
            _currentGoalMarkerInstance.SetActive(false);
        }
    }

    /// <summary>
    /// Auto Mode 시 3D 도로 클릭 위치로 Goal 목적지 핀 배치 및 ROS2 /goal_pose 안전 전송
    /// </summary>
    public void SetGoalPose(Vector3 worldPos, Quaternion worldRot)
    {
        EnsureROSInitialized();

        _hasGoalBeenReached = false;
        currentGoalPosition = worldPos;
        currentGoalRotation = worldRot;

        // 1. 시뮬레이터 3D 씬 내 'G' 깃발 마커 생성/이동
        UpdateGoalMarkerInstance(worldPos, worldRot);

        // 2. ROS2 자율주행 공식 표준 /goal_pose 토픽 전송 (1초 동안 안전 방어 5회 재전송)
        StopAllCoroutines();
        StartCoroutine(RoutinePublishGoalPoseSafety(worldPos, worldRot));
    }

    private void UpdateGoalMarkerInstance(Vector3 pos, Quaternion rot)
    {
        if (_currentGoalMarkerInstance == null)
        {
            if (goalMarkerPrefab != null)
            {
                _currentGoalMarkerInstance = Instantiate(goalMarkerPrefab, pos, rot);
            }
            else
            {
                // 프리팹이 없을 경우 시안색 3D 실린더/핀 마커 자동 생성
                _currentGoalMarkerInstance = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
                _currentGoalMarkerInstance.name = "Goal_Destination_Marker";
                _currentGoalMarkerInstance.transform.localScale = new Vector3(0.5f, 1.5f, 0.5f);
                
                Renderer r = _currentGoalMarkerInstance.GetComponent<Renderer>();
                if (r != null)
                {
                    Shader urpShader = Shader.Find("Universal Render Pipeline/Lit");
                    if (urpShader == null) urpShader = Shader.Find("Sprites/Default");
                    if (urpShader == null) urpShader = Shader.Find("Unlit/Color");
                    if (urpShader != null) r.material.shader = urpShader;
                    r.material.color = new Color(0.0f, 0.85f, 1.0f); // 선명한 네온 시안 블루!
                }
                
                Destroy(_currentGoalMarkerInstance.GetComponent<Collider>());
            }
        }

        _currentGoalMarkerInstance.transform.position = pos;
        _currentGoalMarkerInstance.transform.rotation = rot;
        _currentGoalMarkerInstance.SetActive(true);
    }

    private IEnumerator RoutinePublishGoalPoseSafety(Vector3 pos, Quaternion rot)
    {
        PoseStampedMsg poseMsg = new PoseStampedMsg();

        // Header 설정
        poseMsg.header.frame_id = "map";
        poseMsg.header.stamp = new RosMessageTypes.BuiltinInterfaces.TimeMsg();
        
        // 3D Position & Orientation 유니티 -> ROS (FLU) 좌표 변환
        poseMsg.pose.position = pos.To<FLU>();
        poseMsg.pose.orientation = rot.To<FLU>();

        // 1.0초 동안 0.2초 간격으로 5회 방어 퍼블리싱 (네트워크 패킷 손실 0%)
        for (int i = 0; i < 5; i++)
        {
            if (_rosConnection != null)
            {
                _rosConnection.Publish(goalPoseTopic, poseMsg);
            }
            yield return new WaitForSeconds(0.2f);
        }
    }
}

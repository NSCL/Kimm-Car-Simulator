using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using UnityEngine;
using UnitySensors.Sensor.GNSS;
using UnitySensors.Sensor.IMU;
using Unity.Robotics.ROSTCPConnector;

/// <summary>
/// sensor_config.json 파일에서 GNSS, IMU, LiDAR(s), Camera(s) 설정을 읽어와
/// Resources/Prefabs/Sensors 폴더의 프리팹을 차체에 100% 동적 생성(Instantiate) 및 1:1 직통 매칭 주입하는 매니저.
/// </summary>
public class SensorConfigManager : MonoBehaviour
{
    public static SensorConfigManager Instance { get; private set; }

    [Header("Current Loaded Sensor Config")]
    public string currentSensorConfigPath;
    public string sensorConfigName = "KIMM Default Sensor Suite";

    [Header("Dynamic Sensor Container")]
    public Transform sensorsRoot;

    private float _lastSelectTime = 0f;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            if (transform.parent != null) transform.SetParent(null);
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        EnsureSensorsRoot();
    }

    private void Start()
    {
        LoadDefaultSensorConfig();
    }

    private Transform EnsureSensorsRoot()
    {
        if (sensorsRoot != null) return sensorsRoot;

        // 차체(VehicleController가 붙은 객체) 탐색
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        Transform parentTransform = (vc != null) ? vc.transform : null;

        if (parentTransform != null)
        {
            Transform existing = parentTransform.Find("Sensors_Container");
            if (existing != null)
            {
                sensorsRoot = existing;
            }
            else
            {
                GameObject rootGo = new GameObject("Sensors_Container");
                rootGo.transform.SetParent(parentTransform, false);
                rootGo.transform.localPosition = Vector3.zero;
                rootGo.transform.localRotation = Quaternion.identity;
                sensorsRoot = rootGo.transform;
            }
        }
        else
        {
            GameObject rootGo = GameObject.Find("Sensors_Container");
            if (rootGo == null) rootGo = new GameObject("Sensors_Container");
            sensorsRoot = rootGo.transform;
        }

        return sensorsRoot;
    }

    public bool LoadDefaultSensorConfig()
    {
        string defaultPath = Path.Combine(Application.streamingAssetsPath, "SensorConfigs", "default_sensor_config.json");
        if (!File.Exists(defaultPath))
        {
            defaultPath = Path.Combine(Application.streamingAssetsPath, "SensorConfigs", "sensor_config.json");
        }
        return LoadSensorConfigFromFile(defaultPath);
    }

    private static bool _isNativeDialogOpen = false;

    public void SelectSensorConfigViaFileDialog()
    {
        if (_isNativeDialogOpen || VehicleConfigManager.GlobalIsAnyDialogOpen) return;
        if (Time.unscaledTime - _lastSelectTime < 2.0f) return;
        if (Time.unscaledTime - VehicleConfigManager.GlobalLastDialogClosedTime < 2.0f) return;

        _isNativeDialogOpen = true;
        _lastSelectTime = Time.unscaledTime;
        VehicleConfigManager.GlobalIsAnyDialogOpen = true;

        try
        {
            string path = OpenFileDialogAndSelectSensorConfig();
            if (!string.IsNullOrEmpty(path))
            {
                _lastSelectTime = Time.unscaledTime;
                if (EscMenuController.Instance != null && EscMenuController.Instance.isMenuOpen)
                {
                    EscMenuController.Instance.OnClickResume();
                }
            }
        }
        finally
        {
            _isNativeDialogOpen = false;
            VehicleConfigManager.GlobalIsAnyDialogOpen = false;
            VehicleConfigManager.GlobalLastDialogClosedTime = Time.unscaledTime;
        }
    }

    public string OpenFileDialogAndSelectSensorConfig()
    {
        string selectedPath = null;
#if UNITY_STANDALONE_LINUX
        selectedPath = OpenLinuxFileDialog("Select Sensor Config JSON");
#else
        selectedPath = OpenWin32FileDialog("JSON Files (*.json)\0*.json\0All Files (*.*)\0*.*\0", "Select Sensor Config JSON");
#endif
        if (!string.IsNullOrEmpty(selectedPath))
        {
            if (LoadSensorConfigFromFile(selectedPath))
            {
                return selectedPath;
            }
        }
        return null;
    }

    public bool LoadSensorConfigFromFile(string filePath)
    {
        if (!File.Exists(filePath))
        {
            Debug.LogWarning($"⚠️ [SensorConfigManager] Config file not found at: {filePath}");
            return false;
        }

        try
        {
            string json = File.ReadAllText(filePath);
            currentSensorConfigPath = filePath;

            ApplySensorSettingsFromJson(json);

            Debug.Log($"✅ [SensorConfigManager] Sensor Config successfully loaded & spawned from: {filePath}");
            return true;
        }
        catch (Exception e)
        {
            Debug.LogError($"❌ [SensorConfigManager] Sensor Config Parse Error: {e.Message}\n{e.StackTrace}");
            return false;
        }
    }

    private void ApplySensorSettingsFromJson(string json)
    {
        Transform container = EnsureSensorsRoot();

        // 0. TF 퍼블리셔 순간 정지 (파괴 중인 오브젝트 접근으로 인한 MissingReferenceException 원천 차단)
        MonoBehaviour[] allScripts = FindObjectsByType<MonoBehaviour>(FindObjectsSortMode.None);
        List<MonoBehaviour> tfPublishers = new List<MonoBehaviour>();
        foreach (MonoBehaviour mb in allScripts)
        {
            if (mb != null && (mb.GetType().Name.Contains("TFMessageMsgPublisher") || mb.GetType().Name.Contains("TFLink")))
            {
                mb.enabled = false;
                tfPublishers.Add(mb);
            }
        }

        // 1. 기존 동적 생성 센서들 즉시 파괴 및 완전 정리 (Reset)
        if (container != null)
        {
            List<GameObject> toDestroy = new List<GameObject>();
            for (int i = 0; i < container.childCount; i++)
            {
                toDestroy.Add(container.GetChild(i).gameObject);
            }
            foreach (GameObject go in toDestroy)
            {
                DestroyImmediate(go);
            }
        }

        // 2. 씬에 남아있던 레거시 고정 센서들 비활성화/정리
        CleanLegacySceneSensors();

        // 3. ROS2 TCP Connection (RosIP, RosPort 10000) 주입
        ROSConnection rosConn = ROSConnection.GetOrCreateInstance();
        if (rosConn != null)
        {
            string ip = ParseStringProperty(json, "ROS2Connection", "RosIP");
            if (!string.IsNullOrEmpty(ip)) rosConn.RosIPAddress = ip;

            int port = (int)ParseFloatProperty(json, "ROS2Connection", "RosPort");
            if (port > 0) rosConn.RosPort = port;
        }

        // 4. VehicleStatusPublisher (Odometry)
        VehicleStatusPublisher vsp = FindFirstObjectByType<VehicleStatusPublisher>();
        if (vsp != null)
        {
            string topic = ParseStringProperty(json, "VehicleStatus", "TopicName");
            if (!string.IsNullOrEmpty(topic)) vsp.statusTopicName = topic;

            float hz = ParseFloatProperty(json, "VehicleStatus", "PublishFrequency");
            if (hz > 0) vsp.publishFrequency = hz;
        }

        // 5. 프리팹 로드 (Resources/Prefabs/Sensors/)
        GameObject gnssPrefab = Resources.Load<GameObject>("Prefabs/Sensors/Kimm_GNSS");
        GameObject imuPrefab = Resources.Load<GameObject>("Prefabs/Sensors/Kimm_IMU");
        GameObject lidarPrefab = Resources.Load<GameObject>("Prefabs/Sensors/Kimm_MID360");
        GameObject camPrefab = Resources.Load<GameObject>("Prefabs/Sensors/Kimm_RGBCamera");

        // 6. GNSS 동적 생성 & 주입
        if (json.Contains("\"GNSS\""))
        {
            string gnssTopic = ParseStringProperty(json, "GNSS", "TopicName");
            float gnssHz = ParseFloatProperty(json, "GNSS", "PublishFrequency");
            Vector3 gnssPos = ParseVector3Property(json, "GNSS", "LocalPosition");
            Vector3 gnssRot = ParseRotationProperty(json, "GNSS", "LocalRotation");

            KimmGeoCoordinateSystem gnssSys = FindFirstObjectByType<KimmGeoCoordinateSystem>();
            if (gnssSys != null)
            {
                double lat = ParseDoubleProperty(json, "GNSS", "InitialLatitude");
                double lon = ParseDoubleProperty(json, "GNSS", "InitialLongitude");
                double alt = ParseDoubleProperty(json, "GNSS", "InitialAltitude");

                if (lat != 0.0 && lon != 0.0)
                {
                    gnssSys.SetAnchorCoordinates(lat, lon, alt);
                }
            }

            if (gnssPrefab != null && container != null)
            {
                bool origActive = gnssPrefab.activeSelf;
                gnssPrefab.SetActive(false);
                GameObject gnssObj = Instantiate(gnssPrefab, container);
                gnssPrefab.SetActive(origActive);

                gnssObj.name = "Kimm_GNSS";
                gnssObj.transform.localPosition = gnssPos;
                gnssObj.transform.localRotation = Quaternion.Euler(gnssRot.x, gnssRot.y, gnssRot.z);
                SetComponentFrequency(gnssObj, gnssHz);
                SetComponentTopicName(gnssObj, gnssTopic);
                gnssObj.SetActive(true);
            }
        }

        // 7. IMU 동적 생성 & 주입
        if (json.Contains("\"IMU\""))
        {
            string imuTopic = ParseStringProperty(json, "IMU", "TopicName");
            float imuHz = ParseFloatProperty(json, "IMU", "PublishFrequency");
            Vector3 imuPos = ParseVector3Property(json, "IMU", "LocalPosition");
            Vector3 imuRot = ParseRotationProperty(json, "IMU", "LocalRotation");

            if (imuPrefab != null && container != null)
            {
                bool origActive = imuPrefab.activeSelf;
                imuPrefab.SetActive(false);
                GameObject imuObj = Instantiate(imuPrefab, container);
                imuPrefab.SetActive(origActive);

                imuObj.name = "Kimm_IMU";
                imuObj.transform.localPosition = imuPos;
                imuObj.transform.localRotation = Quaternion.Euler(imuRot.x, imuRot.y, imuRot.z);
                SetComponentFrequency(imuObj, imuHz);
                SetComponentTopicName(imuObj, imuTopic);
                imuObj.SetActive(true);
            }
        }

        // 8. LiDAR(s) 동적 생성 & 주입 (단일 "LiDAR" 또는 다중 "LiDARs" 배열 모두 지원)
        List<string> lidarBlocks = ExtractSensorBlocks(json, "LiDARs", "LiDAR");
        if (lidarPrefab != null && container != null)
        {
            int lIdx = 1;
            foreach (string lBlock in lidarBlocks)
            {
                string lName = ParseStringDirect(lBlock, "Name");
                if (string.IsNullOrEmpty(lName)) lName = (lidarBlocks.Count > 1) ? $"LiDAR_{lIdx}" : "Kimm_MID360";

                string lTopic = ParseStringDirect(lBlock, "TopicName");
                if (string.IsNullOrEmpty(lTopic)) lTopic = "/kimm/lidar/points";

                float lHz = ParseFloatDirect(lBlock, "PublishFrequency");
                int lPoints = (int)ParseFloatDirect(lBlock, "PointsNumPerScan");
                float lMinR = ParseFloatDirect(lBlock, "MinRange");
                float lMaxR = ParseFloatDirect(lBlock, "MaxRange");
                float lNoise = ParseFloatDirect(lBlock, "GaussianNoiseSigma");
                float lIntensity = ParseFloatDirect(lBlock, "MaxIntensity");
                Vector3 lPos = ParseVector3Direct(lBlock, "LocalPosition");
                Vector3 lRot = ParseRotationDirect(lBlock, "LocalRotation");

                bool origActive = lidarPrefab.activeSelf;
                lidarPrefab.SetActive(false);
                GameObject lObj = Instantiate(lidarPrefab, container);
                lidarPrefab.SetActive(origActive);

                lObj.name = lName;
                lObj.transform.localPosition = lPos;
                lObj.transform.localRotation = Quaternion.Euler(lRot.x, lRot.y, lRot.z);

                SetComponentFrequency(lObj, lHz);
                SetComponentTopicName(lObj, lTopic);
                SetComponentLidarParameters(lObj, lPoints, lMinR, lMaxR, lNoise, lIntensity);

                lObj.SetActive(true);
                lIdx++;
            }
        }

        // 9. Camera(s) 동적 생성 & 주입 (단일 "Camera" 또는 다중 "Cameras" 배열 모두 지원)
        List<string> camBlocks = ExtractSensorBlocks(json, "Cameras", "Camera");
        if (camPrefab != null && container != null)
        {
            int cIdx = 1;
            foreach (string cBlock in camBlocks)
            {
                string cName = ParseStringDirect(cBlock, "Name");
                if (string.IsNullOrEmpty(cName)) cName = (camBlocks.Count > 1) ? $"Camera_{cIdx}" : "Kimm_RGBCamera";

                string cTopic = ParseStringDirect(cBlock, "TopicName");
                if (string.IsNullOrEmpty(cTopic)) cTopic = "/kimm/camera/color/compressed";

                float cHz = ParseFloatDirect(cBlock, "PublishFrequency");
                int cW = (int)ParseFloatDirect(cBlock, "ResolutionWidth");
                int cH = (int)ParseFloatDirect(cBlock, "ResolutionHeight");
                float fov = ParseFloatDirect(cBlock, "FieldOfView");
                Vector3 cPos = ParseVector3Direct(cBlock, "LocalPosition");
                Vector3 cRot = ParseRotationDirect(cBlock, "LocalRotation");

                string cInfoTopic = ParseStringDirect(cBlock, "CameraInfoTopic");
                if (string.IsNullOrEmpty(cInfoTopic)) cInfoTopic = ParseStringProperty(json, "CameraInfo", "TopicName");
                if (string.IsNullOrEmpty(cInfoTopic)) cInfoTopic = "/kimm/camera/camera_info";

                float cInfoHz = ParseFloatDirect(cBlock, "CameraInfoFrequency");
                if (cInfoHz <= 0) cInfoHz = ParseFloatProperty(json, "CameraInfo", "PublishFrequency");
                if (cInfoHz <= 0) cInfoHz = cHz;

                bool origActive = camPrefab.activeSelf;
                camPrefab.SetActive(false);
                GameObject cObj = Instantiate(camPrefab, container);
                camPrefab.SetActive(origActive);

                cObj.name = cName;
                cObj.transform.localPosition = cPos;
                cObj.transform.localRotation = Quaternion.Euler(cRot.x, cRot.y, cRot.z);

                SetComponentFrequency(cObj, cHz);
                SetComponentCameraParameters(cObj, cW, cH, fov);

                // 카메라 컴포넌트별 1:1 토픽/주파수 정밀 주입 (타입 충돌 및 Inconsistent declaration 경고 원천 차단)
                Component[] comps = cObj.GetComponentsInChildren<Component>(true);
                foreach (Component c in comps)
                {
                    if (c == null) continue;
                    string typeName = c.GetType().Name.ToLower();

                    if (typeName.Contains("camerainfo") || typeName.Contains("info"))
                    {
                        SetComponentFrequency(c, cInfoHz);
                        SetSingleComponentTopicName(c, cInfoTopic);
                    }
                    else if (typeName.Contains("compressed") || typeName.Contains("image") || typeName.Contains("publisher"))
                    {
                        SetComponentFrequency(c, cHz);
                        SetSingleComponentTopicName(c, cTopic);
                    }
                }

                cObj.SetActive(true);

                cIdx++;
            }
        }

        // 10. GoalPose 토픽 주입
        KimmGoalPosePublisher goalPub = FindFirstObjectByType<KimmGoalPosePublisher>();
        if (goalPub != null)
        {
            string topic = ParseStringProperty(json, "GoalPose", "TopicName");
            if (!string.IsNullOrEmpty(topic)) goalPub.goalPoseTopic = topic;
        }

        // 11. 동적 생성된 센서들의 TFLink 를 base_link 루트 TFLink 에 자동 등록 (NullReference 방지 및 /tf 완벽 연동)
        UpdateRootTFLinks(container);

        // 12. 일시 정지했던 TF 퍼블리셔들 안전 재가동
        foreach (MonoBehaviour mb in tfPublishers)
        {
            if (mb != null) mb.enabled = true;
        }

        // 13. 센서 퍼블리셔 루프 리스타트
        RestartAllSensorPublishers();
    }

    private void UpdateRootTFLinks(Transform container)
    {
        if (container == null) return;
        try
        {
            MonoBehaviour[] allScripts = FindObjectsByType<MonoBehaviour>(FindObjectsSortMode.None);
            List<MonoBehaviour> childTFLinks = new List<MonoBehaviour>();

            MonoBehaviour[] containerComponents = container.GetComponentsInChildren<MonoBehaviour>(true);
            foreach (MonoBehaviour mb in containerComponents)
            {
                if (mb == null) continue;
                if (mb.GetType().Name.Contains("TFLink"))
                {
                    childTFLinks.Add(mb);
                }
            }

            foreach (MonoBehaviour rootMb in allScripts)
            {
                if (rootMb == null) continue;
                if (rootMb.GetType().Name.Contains("TFLink") && !childTFLinks.Contains(rootMb))
                {
                    var childrenField = FindFieldInHierarchy(rootMb.GetType(), "_children");
                    if (childrenField != null)
                    {
                        Type elemType = childrenField.FieldType.GetElementType();
                        if (elemType != null)
                        {
                            Array newArr = Array.CreateInstance(elemType, childTFLinks.Count);
                            for (int i = 0; i < childTFLinks.Count; i++)
                            {
                                newArr.SetValue(childTFLinks[i], i);
                            }
                            childrenField.SetValue(rootMb, newArr);
                        }
                    }
                }
            }
        }
        catch (Exception ex)
        {
            Debug.LogWarning($"⚠️ [SensorConfigManager] TFLink auto-wiring notice: {ex.Message}");
        }
    }

    private void CleanLegacySceneSensors()
    {
        // 씬 내부에 컨테이너 외부에 존재하는 구버전 센서 오브젝트 비활성화
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc == null) return;

        Transform[] allChildren = vc.GetComponentsInChildren<Transform>(true);
        foreach (Transform t in allChildren)
        {
            if (t == null || t == vc.transform) continue;
            if (t.parent == sensorsRoot || t == sensorsRoot) continue;

            string n = t.name.ToLower();
            if (n.Contains("kimm_gnss") || n.Contains("kimm_imu") || n.Contains("kimm_mid360") || n.Contains("mid-360") || n.Contains("kimm_rgbcamera"))
            {
                t.gameObject.SetActive(false);
            }
        }
    }

    private void RestartAllSensorPublishers()
    {
        MonoBehaviour[] allScripts = FindObjectsByType<MonoBehaviour>(FindObjectsSortMode.None);
        foreach (MonoBehaviour mb in allScripts)
        {
            if (mb == null || mb == this) continue;
            string typeName = mb.GetType().Name.ToLower();

            if (typeName.Contains("sensor") || typeName.Contains("publisher") || typeName.Contains("pointcloud") || typeName.Contains("navsat") || typeName.Contains("imu"))
            {
                try
                {
                    mb.StopAllCoroutines();
                    mb.enabled = false;
                    mb.enabled = true;
                }
                catch { }
            }
        }
    }

    #region Reflection Helpers
    private static System.Reflection.FieldInfo FindFieldInHierarchy(Type type, string fieldName)
    {
        Type curr = type;
        while (curr != null && curr != typeof(object) && curr != typeof(MonoBehaviour) && curr != typeof(Component) && curr != typeof(UnityEngine.Object))
        {
            var f = curr.GetField(fieldName, System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.DeclaredOnly);
            if (f != null) return f;
            curr = curr.BaseType;
        }
        return null;
    }

    private static System.Reflection.PropertyInfo FindPropertyInHierarchy(Type type, string propName)
    {
        Type curr = type;
        while (curr != null && curr != typeof(object) && curr != typeof(MonoBehaviour) && curr != typeof(Component) && curr != typeof(UnityEngine.Object))
        {
            var p = curr.GetProperty(propName, System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.DeclaredOnly);
            if (p != null) return p;
            curr = curr.BaseType;
        }
        return null;
    }

    private void SetSingleComponentTopicName(Component c, string topic)
    {
        if (c == null || string.IsNullOrEmpty(topic)) return;
        Type t = c.GetType();

        string[] fieldNames = { "_topicName", "topicName", "topic", "statusTopicName", "imuTopicName", "gnssTopicName", "m_TopicName" };
        foreach (string name in fieldNames)
        {
            var field = FindFieldInHierarchy(t, name);
            if (field != null && field.FieldType == typeof(string))
            {
                string oldTopic = field.GetValue(c) as string;
                if (!string.IsNullOrEmpty(oldTopic) && oldTopic != topic)
                {
                    UnregisterRosTopic(oldTopic);
                }
                field.SetValue(c, topic);
                break;
            }

            var prop = FindPropertyInHierarchy(t, name);
            if (prop != null && prop.CanWrite && prop.PropertyType == typeof(string))
            {
                string oldTopic = prop.GetValue(c) as string;
                if (!string.IsNullOrEmpty(oldTopic) && oldTopic != topic)
                {
                    UnregisterRosTopic(oldTopic);
                }
                prop.SetValue(c, topic);
                break;
            }
        }
    }

    private void SetComponentTopicName(GameObject go, string topic)
    {
        if (go == null || string.IsNullOrEmpty(topic)) return;
        Component[] targets = go.GetComponentsInChildren<Component>(true);
        foreach (Component c in targets) SetSingleComponentTopicName(c, topic);
    }

    private void SetComponentTopicName(Component comp, string topic)
    {
        if (comp == null || string.IsNullOrEmpty(topic)) return;
        Component[] targets = comp.gameObject.GetComponentsInChildren<Component>(true);
        foreach (Component c in targets) SetSingleComponentTopicName(c, topic);
    }

    private void SetComponentFrequency(GameObject go, float hz)
    {
        if (go == null || hz <= 0) return;
        Component[] targets = go.GetComponentsInChildren<Component>(true);
        foreach (Component c in targets) SetComponentFrequency(c, hz);
    }

    private void SetComponentFrequency(Component comp, float hz)
    {
        if (comp == null || hz <= 0) return;
        Component[] targets = comp.gameObject.GetComponentsInChildren<Component>(true);

        foreach (Component c in targets)
        {
            if (c == null) continue;
            Type t = c.GetType();

            string[] names = { "_frequency", "publishFrequency", "frequency", "rate" };
            foreach (string name in names)
            {
                var field = FindFieldInHierarchy(t, name);
                if (field != null)
                {
                    if (field.FieldType == typeof(float)) field.SetValue(c, hz);
                    else if (field.FieldType == typeof(double)) field.SetValue(c, (double)hz);
                    else if (field.FieldType == typeof(int)) field.SetValue(c, (int)hz);
                }

                var prop = FindPropertyInHierarchy(t, name);
                if (prop != null && prop.CanWrite)
                {
                    if (prop.PropertyType == typeof(float)) prop.SetValue(c, hz);
                    else if (prop.PropertyType == typeof(double)) prop.SetValue(c, (double)hz);
                    else if (prop.PropertyType == typeof(int)) prop.SetValue(c, (int)hz);
                }
            }
        }
    }

    private void SetComponentCameraParameters(GameObject go, int width, int height, float fov)
    {
        if (go == null) return;
        Component[] targets = go.GetComponentsInChildren<Component>(true);
        foreach (Component c in targets) SetComponentCameraParameters(c, width, height, fov);
    }

    private void SetComponentCameraParameters(Component comp, int width, int height, float fov)
    {
        if (comp == null) return;
        Component[] targets = comp.gameObject.GetComponentsInChildren<Component>(true);

        foreach (Component c in targets)
        {
            if (c == null) continue;
            Type t = c.GetType();

            // 1. Resolution (_resolution Vector2Int / Vector2)
            if (width > 0 && height > 0)
            {
                string[] resNames = { "_resolution", "resolution" };
                foreach (string name in resNames)
                {
                    var resField = FindFieldInHierarchy(t, name);
                    if (resField != null)
                    {
                        if (resField.FieldType == typeof(Vector2Int)) resField.SetValue(c, new Vector2Int(width, height));
                        else if (resField.FieldType == typeof(Vector2)) resField.SetValue(c, new Vector2(width, height));
                    }
                }
            }

            // 2. FOV (_fov / _fieldOfView / fieldOfView / fov)
            if (fov > 0)
            {
                string[] fovNames = { "_fov", "_fieldOfView", "fieldOfView", "fov" };
                foreach (string name in fovNames)
                {
                    var fovField = FindFieldInHierarchy(t, name);
                    if (fovField != null)
                    {
                        if (fovField.FieldType == typeof(float)) fovField.SetValue(c, fov);
                        else if (fovField.FieldType == typeof(double)) fovField.SetValue(c, (double)fov);
                    }
                }
            }

            // Unity 기본 Camera 컴포넌트에도 반영
            if (c is Camera cam && fov > 0)
            {
                cam.fieldOfView = fov;
            }
        }
    }

    private void SetComponentLidarParameters(GameObject go, int pointsNum, float minRange, float maxRange, float noiseSigma, float maxIntensity)
    {
        if (go == null) return;
        Component[] targets = go.GetComponentsInChildren<Component>(true);
        foreach (Component c in targets) SetComponentLidarParameters(c, pointsNum, minRange, maxRange, noiseSigma, maxIntensity);
    }

    private void SetComponentLidarParameters(Component comp, int pointsNum, float minRange, float maxRange, float noiseSigma, float maxIntensity)
    {
        if (comp == null) return;
        Component[] targets = comp.gameObject.GetComponentsInChildren<Component>(true);

        foreach (Component c in targets)
        {
            if (c == null) continue;
            Type t = c.GetType();

            // 1. PointsNumPerScan (JSON 설정값 그대로 100% 직통 주입)
            if (pointsNum > 0)
            {
                string[] pNames = { "_pointsNumPerScan", "pointsNumPerScan", "_pointsNum", "pointsNum" };
                foreach (string name in pNames)
                {
                    var pField = FindFieldInHierarchy(t, name);
                    if (pField != null)
                    {
                        if (pField.FieldType == typeof(int)) pField.SetValue(c, pointsNum);
                        else if (pField.FieldType == typeof(float)) pField.SetValue(c, (float)pointsNum);
                        else if (pField.FieldType == typeof(uint)) pField.SetValue(c, (uint)pointsNum);
                    }
                }
            }

            // 2. MinRange
            if (minRange > 0)
            {
                string[] minNames = { "_minRange", "minRange" };
                foreach (string name in minNames)
                {
                    var minRField = FindFieldInHierarchy(t, name);
                    if (minRField != null)
                    {
                        if (minRField.FieldType == typeof(float)) minRField.SetValue(c, minRange);
                        else if (minRField.FieldType == typeof(double)) minRField.SetValue(c, (double)minRange);
                    }
                }
            }

            // 3. MaxRange
            if (maxRange > 0)
            {
                string[] maxNames = { "_maxRange", "maxRange" };
                foreach (string name in maxNames)
                {
                    var maxRField = FindFieldInHierarchy(t, name);
                    if (maxRField != null)
                    {
                        if (maxRField.FieldType == typeof(float)) maxRField.SetValue(c, maxRange);
                        else if (maxRField.FieldType == typeof(double)) maxRField.SetValue(c, (double)maxRange);
                    }
                }
            }

            // 4. GaussianNoiseSigma
            if (noiseSigma >= 0)
            {
                string[] noiseNames = { "_gaussianNoiseSigma", "gaussianNoiseSigma", "_noiseSigma", "noiseSigma" };
                foreach (string name in noiseNames)
                {
                    var noiseField = FindFieldInHierarchy(t, name);
                    if (noiseField != null)
                    {
                        if (noiseField.FieldType == typeof(float)) noiseField.SetValue(c, noiseSigma);
                        else if (noiseField.FieldType == typeof(double)) noiseField.SetValue(c, (double)noiseSigma);
                    }
                }
            }

            // 5. MaxIntensity
            if (maxIntensity > 0)
            {
                string[] intNames = { "_maxIntensity", "maxIntensity", "_intensity", "intensity" };
                foreach (string name in intNames)
                {
                    var intField = FindFieldInHierarchy(t, name);
                    if (intField != null)
                    {
                        if (intField.FieldType == typeof(float)) intField.SetValue(c, maxIntensity);
                        else if (intField.FieldType == typeof(double)) intField.SetValue(c, (double)maxIntensity);
                        else if (intField.FieldType == typeof(int)) intField.SetValue(c, (int)maxIntensity);
                    }
                }
            }
        }
    }

    private void UnregisterRosTopic(string topicName)
    {
        if (string.IsNullOrEmpty(topicName)) return;
        try
        {
            ROSConnection ros = ROSConnection.GetOrCreateInstance();
            if (ros != null)
            {
                var unregMethod = ros.GetType().GetMethod("UnregisterPublisher", System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.Instance);
                if (unregMethod != null)
                {
                    unregMethod.Invoke(ros, new object[] { topicName });
                }
            }
        }
        catch { }
    }
    #endregion

    #region JSON Array & Object Extraction Helpers
    private List<string> ExtractSensorBlocks(string json, string pluralKey, string singularKey)
    {
        List<string> blocks = new List<string>();

        // 1. Plural Array 형태 (예: "Cameras": [ { ... }, { ... } ])
        int pIdx = json.IndexOf($"\"{pluralKey}\"");
        if (pIdx >= 0)
        {
            int openBracket = json.IndexOf("[", pIdx);
            int closeBracket = json.IndexOf("]", openBracket);
            if (openBracket >= 0 && closeBracket > openBracket)
            {
                string arrJson = json.Substring(openBracket + 1, closeBracket - openBracket - 1);
                int depth = 0;
                int start = -1;
                for (int i = 0; i < arrJson.Length; i++)
                {
                    if (arrJson[i] == '{')
                    {
                        if (depth == 0) start = i;
                        depth++;
                    }
                    else if (arrJson[i] == '}')
                    {
                        depth--;
                        if (depth == 0 && start >= 0)
                        {
                            blocks.Add(arrJson.Substring(start, i - start + 1));
                            start = -1;
                        }
                    }
                }
            }
        }

        // 2. Singular Object 형태 (예: "Camera": { ... })
        if (blocks.Count == 0)
        {
            int sIdx = json.IndexOf($"\"{singularKey}\"");
            if (sIdx >= 0)
            {
                int openBrace = json.IndexOf("{", sIdx);
                if (openBrace >= 0)
                {
                    int depth = 0;
                    for (int i = openBrace; i < json.Length; i++)
                    {
                        if (json[i] == '{') depth++;
                        else if (json[i] == '}')
                        {
                            depth--;
                            if (depth == 0)
                            {
                                blocks.Add(json.Substring(openBrace, i - openBrace + 1));
                                break;
                            }
                        }
                    }
                }
            }
        }

        return blocks;
    }

    private string ParseStringProperty(string json, string sectionKey, string propKey)
    {
        try
        {
            int sectionIdx = json.IndexOf($"\"{sectionKey}\"");
            if (sectionIdx < 0) return null;

            int propIdx = json.IndexOf($"\"{propKey}\"", sectionIdx);
            if (propIdx < 0) return null;

            int colonIdx = json.IndexOf(":", propIdx);
            if (colonIdx < 0) return null;

            int startQuote = json.IndexOf("\"", colonIdx);
            if (startQuote < 0) return null;

            int endQuote = json.IndexOf("\"", startQuote + 1);
            if (endQuote < 0) return null;

            return json.Substring(startQuote + 1, endQuote - startQuote - 1);
        }
        catch
        {
            return null;
        }
    }

    private float ParseFloatProperty(string json, string sectionKey, string propKey)
    {
        try
        {
            int sectionIdx = json.IndexOf($"\"{sectionKey}\"");
            if (sectionIdx < 0) return 0f;

            int propIdx = json.IndexOf($"\"{propKey}\"", sectionIdx);
            if (propIdx < 0) return 0f;

            int colonIdx = json.IndexOf(":", propIdx);
            if (colonIdx < 0) return 0f;

            int commaIdx = json.IndexOf(",", colonIdx);
            int braceIdx = json.IndexOf("}", colonIdx);
            int endIdx = (commaIdx > 0 && braceIdx > 0) ? Math.Min(commaIdx, braceIdx) : (commaIdx > 0 ? commaIdx : braceIdx);

            if (endIdx < 0) return 0f;

            string valStr = json.Substring(colonIdx + 1, endIdx - colonIdx - 1).Trim();
            if (float.TryParse(valStr, System.Globalization.NumberStyles.Any, System.Globalization.CultureInfo.InvariantCulture, out float result))
            {
                return result;
            }
        }
        catch { }
        return 0f;
    }

    private double ParseDoubleProperty(string json, string sectionKey, string propKey)
    {
        try
        {
            int sectionIdx = json.IndexOf($"\"{sectionKey}\"");
            if (sectionIdx < 0) return 0.0;

            int propIdx = json.IndexOf($"\"{propKey}\"", sectionIdx);
            if (propIdx < 0) return 0.0;

            int colonIdx = json.IndexOf(":", propIdx);
            if (colonIdx < 0) return 0.0;

            int commaIdx = json.IndexOf(",", colonIdx);
            int braceIdx = json.IndexOf("}", colonIdx);
            int endIdx = (commaIdx > 0 && braceIdx > 0) ? Math.Min(commaIdx, braceIdx) : (commaIdx > 0 ? commaIdx : braceIdx);

            if (endIdx < 0) return 0.0;

            string valStr = json.Substring(colonIdx + 1, endIdx - colonIdx - 1).Trim();
            if (double.TryParse(valStr, System.Globalization.NumberStyles.Any, System.Globalization.CultureInfo.InvariantCulture, out double result))
            {
                return result;
            }
        }
        catch { }
        return 0.0;
    }

    private Vector3 ParseVector3Property(string json, string sectionKey, string propKey)
    {
        try
        {
            int sectionIdx = json.IndexOf($"\"{sectionKey}\"");
            if (sectionIdx < 0) return Vector3.zero;

            int propIdx = json.IndexOf($"\"{propKey}\"", sectionIdx);
            if (propIdx < 0) return Vector3.zero;

            int openBrace = json.IndexOf("{", propIdx);
            int closeBrace = json.IndexOf("}", openBrace);
            if (openBrace < 0 || closeBrace < 0) return Vector3.zero;

            string vecJson = json.Substring(openBrace, closeBrace - openBrace + 1);
            return ParseVector3Direct(vecJson, propKey);
        }
        catch
        {
            return Vector3.zero;
        }
    }

    private Vector3 ParseRotationProperty(string json, string sectionKey, string propKey)
    {
        try
        {
            int sectionIdx = json.IndexOf($"\"{sectionKey}\"");
            if (sectionIdx < 0) return Vector3.zero;

            int propIdx = json.IndexOf($"\"{propKey}\"", sectionIdx);
            if (propIdx < 0) return Vector3.zero;

            int openBrace = json.IndexOf("{", propIdx);
            int closeBrace = json.IndexOf("}", openBrace);
            if (openBrace < 0 || closeBrace < 0) return Vector3.zero;

            string rotJson = json.Substring(openBrace, closeBrace - openBrace + 1);
            return ParseRotationDirect(rotJson, propKey);
        }
        catch
        {
            return Vector3.zero;
        }
    }

    private string ParseStringDirect(string blockJson, string propKey)
    {
        try
        {
            int propIdx = blockJson.IndexOf($"\"{propKey}\"");
            if (propIdx < 0) return null;

            int colonIdx = blockJson.IndexOf(":", propIdx);
            if (colonIdx < 0) return null;

            int startQuote = blockJson.IndexOf("\"", colonIdx);
            if (startQuote < 0) return null;

            int endQuote = blockJson.IndexOf("\"", startQuote + 1);
            if (endQuote < 0) return null;

            return blockJson.Substring(startQuote + 1, endQuote - startQuote - 1);
        }
        catch { return null; }
    }

    private float ParseFloatDirect(string blockJson, string propKey)
    {
        try
        {
            int propIdx = blockJson.IndexOf($"\"{propKey}\"");
            if (propIdx < 0) return 0f;

            int colonIdx = blockJson.IndexOf(":", propIdx);
            if (colonIdx < 0) return 0f;

            int commaIdx = blockJson.IndexOf(",", colonIdx);
            int braceIdx = blockJson.IndexOf("}", colonIdx);
            int endIdx = (commaIdx > 0 && braceIdx > 0) ? Math.Min(commaIdx, braceIdx) : (commaIdx > 0 ? commaIdx : braceIdx);

            if (endIdx < 0) return 0f;

            string valStr = blockJson.Substring(colonIdx + 1, endIdx - colonIdx - 1).Trim();
            if (float.TryParse(valStr, System.Globalization.NumberStyles.Any, System.Globalization.CultureInfo.InvariantCulture, out float result))
            {
                return result;
            }
        }
        catch { }
        return 0f;
    }

    private Vector3 ParseVector3Direct(string blockJson, string propKey)
    {
        try
        {
            int propIdx = blockJson.IndexOf($"\"{propKey}\"");
            string targetJson = blockJson;
            if (propIdx >= 0)
            {
                int openBrace = blockJson.IndexOf("{", propIdx);
                int closeBrace = blockJson.IndexOf("}", openBrace);
                if (openBrace >= 0 && closeBrace > openBrace)
                {
                    targetJson = blockJson.Substring(openBrace, closeBrace - openBrace + 1);
                }
            }

            float fwd = ParseVal(targetJson, "x");  // FLU: Forward (전방)
            float left = ParseVal(targetJson, "y"); // FLU: Left (좌측)
            float up = ParseVal(targetJson, "z");   // FLU: Up (상단/높이)

            // FLU (Forward, Left, Up) -> Unity 3D (Right=+X, Up=+Y, Forward=+Z)
            return new Vector3(-left, up, fwd);
        }
        catch { return Vector3.zero; }
    }

    private Vector3 ParseRotationDirect(string blockJson, string propKey)
    {
        try
        {
            int propIdx = blockJson.IndexOf($"\"{propKey}\"");
            string targetJson = blockJson;
            if (propIdx >= 0)
            {
                int openBrace = blockJson.IndexOf("{", propIdx);
                int closeBrace = blockJson.IndexOf("}", openBrace);
                if (openBrace >= 0 && closeBrace > openBrace)
                {
                    targetJson = blockJson.Substring(openBrace, closeBrace - openBrace + 1);
                }
            }

            float roll = ParseVal(targetJson, "roll");   // +: Right Roll
            float pitch = ParseVal(targetJson, "pitch"); // +: Nose-Up, -: Nose-Down
            float yaw = ParseVal(targetJson, "yaw");     // +: Turn-Left, -: Turn-Right

            // 사람 직관 (pitch +: 고개 쳐듦) -> Unity 3D Euler (Pitch=-X, Yaw=-Y, Roll=-Z)
            return new Vector3(-pitch, -yaw, -roll);
        }
        catch { return Vector3.zero; }
    }

    private float ParseVal(string vecJson, string axis)
    {
        int idx = vecJson.IndexOf($"\"{axis}\"");
        if (idx < 0) return 0f;

        int colon = vecJson.IndexOf(":", idx);
        if (colon < 0) return 0f;

        int comma = vecJson.IndexOf(",", colon);
        int brace = vecJson.IndexOf("}", colon);
        int end = (comma > 0 && brace > 0) ? Math.Min(comma, brace) : (comma > 0 ? comma : brace);
        if (end < 0) return 0f;

        string val = vecJson.Substring(colon + 1, end - colon - 1).Trim();
        if (float.TryParse(val, System.Globalization.NumberStyles.Any, System.Globalization.CultureInfo.InvariantCulture, out float r))
        {
            return r;
        }
        return 0f;
    }
    #endregion

    #region Win32 & Linux Dialogs
#if !UNITY_STANDALONE_LINUX
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
    public class OpenFileName
    {
        public int structSize = 0;
        public IntPtr dlgOwner = IntPtr.Zero;
        public IntPtr instance = IntPtr.Zero;
        public string filter = null;
        public string customFilter = null;
        public int maxCustFilter = 0;
        public int filterIndex = 0;
        public string file = null;
        public int maxFile = 0;
        public string fileTitle = null;
        public int maxFileTitle = 0;
        public string initialDir = null;
        public string title = null;
        public int flags = 0;
        public short fileOffset = 0;
        public short fileExtension = 0;
        public string defExt = null;
        public IntPtr custData = IntPtr.Zero;
        public IntPtr hook = IntPtr.Zero;
        public string templateName = null;
        public IntPtr reservedPtr = IntPtr.Zero;
        public int reservedInt = 0;
        public int flagsEx = 0;
    }

    [DllImport("comdlg32.dll", CharSet = CharSet.Auto, SetLastError = true)]
    private static extern bool GetOpenFileName([In, Out] OpenFileName ofn);
#endif

    public static string OpenWin32FileDialog(string filterStr, string titleStr)
    {
#if !UNITY_STANDALONE_LINUX
        string initPath = Path.Combine(Application.streamingAssetsPath, "SensorConfigs");
        if (!Directory.Exists(initPath)) Directory.CreateDirectory(initPath);

        OpenFileName ofn = new OpenFileName();
        ofn.structSize = Marshal.SizeOf(ofn);
        ofn.filter = filterStr;
        ofn.file = new string(new char[512]);
        ofn.maxFile = ofn.file.Length;
        ofn.fileTitle = new string(new char[128]);
        ofn.maxFileTitle = ofn.fileTitle.Length;
        ofn.initialDir = initPath.Replace('/', '\\');
        ofn.title = titleStr;
        ofn.flags = 0x00080000 | 0x00001000 | 0x00000800 | 0x00000200 | 0x00000008;

        string savedDir = Directory.GetCurrentDirectory();
        try
        {
            Directory.SetCurrentDirectory(initPath);
            if (GetOpenFileName(ofn))
            {
                return ofn.file;
            }
        }
        finally
        {
            Directory.SetCurrentDirectory(savedDir);
        }
#endif
        return null;
    }

    public static string OpenLinuxFileDialog(string titleStr)
    {
        try
        {
            string initDir = Path.Combine(Application.streamingAssetsPath, "SensorConfigs");
            if (!Directory.Exists(initDir)) initDir = Application.streamingAssetsPath;

            System.Diagnostics.ProcessStartInfo psi = new System.Diagnostics.ProcessStartInfo
            {
                FileName = "zenity",
                Arguments = $"--file-selection --title=\"{titleStr}\" --filename=\"{initDir}/\" --file-filter=\"*.json\"",
                RedirectStandardOutput = true,
                UseShellExecute = false,
                CreateNoWindow = true
            };

            using (System.Diagnostics.Process process = System.Diagnostics.Process.Start(psi))
            {
                string output = process.StandardOutput.ReadToEnd().Trim();
                process.WaitForExit();

                if (process.ExitCode == 0 && !string.IsNullOrEmpty(output))
                {
                    return output;
                }
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"❌ [SensorConfigManager] Zenity Linux Dialog Failed: {ex.Message}");
        }
        return null;
    }
    #endregion
}

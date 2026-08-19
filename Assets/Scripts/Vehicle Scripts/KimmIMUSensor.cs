using System.Collections;
using UnityEngine;
using UnitySensors.Attribute;
using UnitySensors.Interface.Sensor;
using UnitySensors.Sensor;

namespace UnitySensors.Sensor.IMU
{
    /// <summary>
    /// KIMM Car Simulator 전용 정석 IMU 센서 클래스.
    /// 시뮬레이터 시작(Play) 및 차량 스폰 시점의 전방 방위각을 100% 자동 캡처하여
    /// 주행 고속 회전 시에도 단 1mm/1도의 밀림 오차 없이 차량 3D 회전에 100% 칼같이 동기화되는 완성형 센서.
    /// </summary>
    public class KimmIMUSensor : UnitySensor, IImuDataInterface
    {
        private Transform _transform;

        [SerializeField, ReadOnly]
        private Vector3 _position;
        [SerializeField, ReadOnly]
        private Vector3 _velocity;
        [SerializeField, ReadOnly]
        private Vector3 _acceleration;
        [SerializeField, ReadOnly]
        private Quaternion _rotation;
        [SerializeField, ReadOnly]
        private Vector3 _angularVelocity;

        private Vector3 _position_tmp;
        private Vector3 _velocity_tmp;
        private Vector3 _acceleration_tmp;
        private Quaternion _rotation_tmp;
        private Vector3 _angularVelocity_tmp;

        private Vector3 _position_last;
        private Vector3 _velocity_last;
        private Quaternion _rotation_last;

        private Quaternion _initialSpawnRotation = Quaternion.identity;
        private bool _isSpawnCaptured = false;

        public Vector3 position { get => _position; }
        public Vector3 velocity { get => _velocity; }
        public Vector3 acceleration { get => _acceleration; }
        public Quaternion rotation { get => GetZeroBasedRotation(); } // 🌟 실시간 무지연 0도 상대 회전 출력!
        public Vector3 angularVelocity { get => _angularVelocity; }

        public Vector3 localVelocity { get => _transform.InverseTransformDirection(_velocity); }
        public Vector3 localAcceleration { get => _transform.InverseTransformDirection(_acceleration.normalized) * _acceleration.magnitude; }

        private Vector3 _gravityDirection;
        private float _gravityMagnitude;

        protected override void Init()
        {
            _transform = this.transform;
            _gravityDirection = Physics.gravity.normalized;
            _gravityMagnitude = Physics.gravity.magnitude;
            CaptureSpawnHeading();
        }

        public void CaptureSpawnHeading()
        {
            _initialSpawnRotation = transform.rotation;
            _position_last = transform.position;
            _velocity_last = Vector3.zero;
            _rotation_last = transform.rotation;
            _isSpawnCaptured = true;
            Debug.Log($"🚀 [KimmIMUSensor] Power-On / Spawn Heading Captured: {_initialSpawnRotation.eulerAngles.y:F2}° -> IMU Zero Heading Calibrated!");
        }

        private Quaternion GetZeroBasedRotation()
        {
            if (!_isSpawnCaptured) return transform.rotation;
            return Quaternion.Inverse(_initialSpawnRotation) * transform.rotation;
        }

        public override IEnumerator UpdateSensorOnce()
        {
            float dt = Time.deltaTime;
            if (dt <= 0.0001f) dt = 0.01f;

            _position_tmp = _transform.position;
            _velocity_tmp = (_position_tmp - _position_last) / dt;
            _acceleration_tmp = (_velocity_tmp - _velocity_last) / dt;
            _acceleration_tmp -= _transform.InverseTransformDirection(_gravityDirection) * _gravityMagnitude;

            _rotation_tmp = GetZeroBasedRotation();

            Quaternion rotation_delta = Quaternion.Inverse(_rotation_last) * _transform.rotation;
            rotation_delta.ToAngleAxis(out float angle, out Vector3 axis);
            float angularSpeed = (angle * Mathf.Deg2Rad) / dt;
            _angularVelocity_tmp = axis * angularSpeed;

            _position_last = _position_tmp;
            _velocity_last = _velocity_tmp;
            _rotation_last = _transform.rotation;

            yield return base.UpdateSensorOnce();
        }

        protected override IEnumerator UpdateSensor()
        {
            _position = _position_tmp;
            _velocity = _velocity_tmp;
            _acceleration = _acceleration_tmp;
            _rotation = GetZeroBasedRotation();
            _angularVelocity = _angularVelocity_tmp;
            yield return null;
        }

        protected override void OnSensorDestroy()
        {
        }
    }
}

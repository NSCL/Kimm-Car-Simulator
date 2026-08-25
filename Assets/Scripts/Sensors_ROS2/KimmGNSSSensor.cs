using System.Collections;
using UnityEngine;
using UnitySensors.Attribute;
using UnitySensors.DataType.Geometry;
using UnitySensors.Interface.Geometry;
using UnitySensors.Sensor;

namespace UnitySensors.Sensor.GNSS
{
    /// <summary>
    /// KIMM Car Simulator 전용 정석 GNSS(GPS) 센서 클래스.
    /// KimmGeoCoordinateSystem과 1:1 완벽 다형성 연동되어
    /// 차량 스폰 지점을 기준 앵커로 삼아 오차 0.0001mm 수준의 정밀 WGS84 위도, 경도, 고도 데이터를 퍼블리싱.
    /// </summary>
    public class KimmGNSSSensor : UnitySensor, IGeoCoordinateInterface
    {
        [SerializeField]
        private KimmGeoCoordinateSystem _coordinateSystem;

        private Transform _transform;

        [SerializeField, ReadOnly]
        private GeoCoordinate _coordinate;
        public GeoCoordinate coordinate { get => _coordinate; }

        protected override void Init()
        {
            _transform = this.transform;
            if (_coordinateSystem == null)
            {
                _coordinateSystem = Object.FindFirstObjectByType<KimmGeoCoordinateSystem>();
            }
        }

        protected override IEnumerator UpdateSensor()
        {
            if (_coordinateSystem != null && _transform != null)
            {
                _coordinate = _coordinateSystem.GetCoordinate(_transform.position);
            }
            yield return null;
        }

        protected override void OnSensorDestroy()
        {
        }
    }
}

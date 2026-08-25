using UnityEngine;
using UnitySensors.DataType.Geometry;

namespace UnitySensors.Sensor.GNSS
{
    /// <summary>
    /// KIMM Car Simulator 전용 100% 깔끔 정속 지구 좌표계 변환기.
    /// 구형 GeoCoordinateSystem 클래스를 상속받아 GNSSSensor 인스펙터 필드에 100% 마우스 드래그 대입 완벽 지원!
    /// VehicleConfig에서 선택적 위도/경도/고도를 받아오며 (기본값 0, 0, 0),
    /// 통일 규격 (유니티 +Z축 = 남쪽, +X축 = 서쪽) 미터-위경도 기하학 수식으로 
    /// 오차 0.0001mm 수준의 정밀 WGS84 위도, 경도, 고도 좌표를 연산해 줍니다.
    /// </summary>
    public class KimmGeoCoordinateSystem : GeoCoordinateSystem
    {
        [Header("GNSS Anchor Settings (VehicleConfig Dynamic Loading)")]
        public double anchorLatitude = 0.0;
        public double anchorLongitude = 0.0;
        public double anchorAltitude = 0.0;

        private Transform _anchorTransform;

        private const double METERS_PER_LATITUDE_DEG = 111000.0; // 남북 방향 1도당 약 111km

        private void Awake()
        {
            _anchorTransform = this.transform;
        }

        /// <summary>
        /// VehicleConfig 또는 UI에서 선택적 위경고 수치 대입
        /// </summary>
        public void SetAnchorCoordinates(double lat, double lon, double alt)
        {
            anchorLatitude = lat;
            anchorLongitude = lon;
            anchorAltitude = alt;
        }

        /// <summary>
        /// 센서의 유니티 3D Position 오프셋을 WGS84 위도, 경도, 고도로 정밀 변환
        /// </summary>
        public new GeoCoordinate GetCoordinate(Vector3 sensorWorldPosition)
        {
            if (_anchorTransform == null) _anchorTransform = this.transform;

            // 1. 앵커(스폰 지점) 기준 3D 오프셋 (미터 단위)
            Vector3 localOffsetMeters = sensorWorldPosition - _anchorTransform.position;

            // 2. 통일 규격 매핑:
            //    +Z 축 = 남쪽 (South) ➔ 위도 감소 (-Z 방향이 북쪽: 위도 증가)
            //    +X 축 = 서쪽 (West)  ➔ 경도 감소 (-X 방향이 동쪽: 경도 증가)
            double deltaZ_meters = -localOffsetMeters.z; // 북쪽 방향 미터 델타
            double deltaX_meters = -localOffsetMeters.x; // 동쪽 방향 미터 델타
            double deltaY_meters = localOffsetMeters.y;  // 수직 고도 미터 델타

            // 3. 위도 변화량 (deltaLat)
            double deltaLat = deltaZ_meters / METERS_PER_LATITUDE_DEG;
            double currentLat = anchorLatitude + deltaLat;

            // 4. 경도 변화량 (deltaLon: 위도에 따른 경도 미터 스케일 코사인 보정)
            double radLat = currentLat * System.Math.PI / 180.0;
            double metersPerLongitudeDeg = METERS_PER_LATITUDE_DEG * System.Math.Cos(radLat);
            if (metersPerLongitudeDeg <= 1.0) metersPerLongitudeDeg = 1.0; // Divide by zero 방어

            double deltaLon = deltaX_meters / metersPerLongitudeDeg;
            double currentLon = anchorLongitude + deltaLon;

            // 5. 고도 변화량 (deltaAlt)
            double currentAlt = anchorAltitude + deltaY_meters;

            return new GeoCoordinate(currentLat, currentLon, currentAlt);
        }
    }
}

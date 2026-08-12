using UnityEngine;

/// <summary>
/// 바퀴 위치에서 지면까지의 고도(hitPointY), 기울기(Qx, Qy), 실제 거리를 감지하는 지면 센서 클래스.
/// M-City 등 맵 본연의 3D 지면 메쉬 고도를 순수하게 감지합니다.
/// </summary>
public class WheelGroundSensor : MonoBehaviour
{
    [Header("Sensor Settings")]
    public float wheelRadius = 0.35f;      // 타이어 반지름
    public float maxRayDistance = 3.0f;    // 레이캐스트 최대 거리

    // [Output] VehicleController 및 FMU로 전달할 지면 연산 출력값
    public float distanceFromGround; // 지면까지의 실제 거리
    public float hitPointY;          // 감지된 지면의 실제 월드 Y 좌표 (FMU gz 입력용)
    public float hitQx;              // 지면 경사각 Roll 회전 쿼터니언 x 성분
    public float hitQy;              // 지면 경사각 Pitch 회전 쿼터니언 y 성분
    public bool isGrounded;          // 지면 감지 여부

    [Header("Debug")]
    public bool enableDebugLog = false;

    private static int _targetLayerMask = -1;

    private void Awake()
    {
        if (_targetLayerMask == -1)
        {
            int ignoreBit = LayerMask.GetMask("Ignore Raycast", "UI", "Vehicle");
            _targetLayerMask = ~ignoreBit;
        }
    }

    /// <summary>
    /// 차량 바퀴 위치에서 아래 방향(-transform.up)으로 레이캐스트를 발사하여 지면 정보(gz, qx, qy) 순수 연산
    /// </summary>
    public void CalculateGroundForces()
    {
        Vector3 rayOrigin = transform.position + (Vector3.up * 0.1f);
        Vector3 rayDirection = Vector3.down;

        RaycastHit hit;

        if (Physics.Raycast(rayOrigin, rayDirection, out hit, maxRayDistance, _targetLayerMask))
        {
            if (hit.transform.IsChildOf(transform.root))
            {
                RaycastHit[] hits = Physics.RaycastAll(rayOrigin, rayDirection, maxRayDistance, _targetLayerMask);
                bool foundMap = false;
                foreach (var h in hits)
                {
                    if (!h.transform.IsChildOf(transform.root))
                    {
                        hit = h;
                        foundMap = true;
                        break;
                    }
                }
                if (!foundMap)
                {
                    isGrounded = false;
                    return;
                }
            }

            isGrounded = true;
            distanceFromGround = hit.distance;
            hitPointY = hit.point.y;

            Quaternion groundRotation = Quaternion.FromToRotation(Vector3.up, hit.normal);
            hitQx = groundRotation.x;
            hitQy = groundRotation.y;
        }
        else
        {
            isGrounded = false;
            distanceFromGround = maxRayDistance;
            hitPointY = transform.position.y - wheelRadius;
            hitQx = 0f;
            hitQy = 0f;
        }
    }
}
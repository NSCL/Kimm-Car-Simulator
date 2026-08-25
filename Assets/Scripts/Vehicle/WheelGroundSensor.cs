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
    public float hitQx;              // 타이어 전진축 기준 지면 전후 경사각 Pitch (라디안)
    public float hitQy;              // 타이어 횡축 기준 지면 좌우 경사각 Roll (라디안)
    public bool isGrounded;          // 지면 감지 여부

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

            // 1. [진행 방향(Heading/Yaw) 좌표계 분해]:
            //    - 바퀴/차체의 수평 진행 방향(Yaw 각도)만을 추출하여 지면 법선 벡터(hit.normal)를 평면 회전시킵니다.
            float wheelYaw = transform.eulerAngles.y;
            Vector3 headingNormal = Quaternion.Euler(0f, -wheelYaw, 0f) * hit.normal;

            // 2. [FMU 규격 오일러 각도 산출 (라디안 단위)]:
            //    - hitQx (Pitch -> FMU qy): 고개 들림(오르막/Nose-Up) 시 음수(-), 내리막 시 양수(+)
            //    - hitQy (Roll  -> FMU qx): 우측 뱅크(Roll Right) 시 양수(+), 좌측 뱅크 시 음수(-)
            hitQx = Mathf.Atan2(headingNormal.z, headingNormal.y); // Pitch (오르막 = 음수)
            hitQy = Mathf.Atan2(headingNormal.x, headingNormal.y); // Roll (우측 = 양수, 좌측 = 음수)
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
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

            // 1. [좌표계 변환]: 지면 법선 벡터(hit.normal)를 '타이어(바퀴) 로컬 좌표계'로 회전 변환
            //    -> 차가 어느 방향(Heading)을 보고 있든, 타이어의 전진/횡방향 시선 기준 노면 방향으로 1:1 정렬
            Vector3 localNormal = transform.InverseTransformDirection(hit.normal);

            // 2. [오일러 각도 산출]: 타이어 접지면 기준의 순수 Roll / Pitch 각도 (라디안 단위) 정밀 계산
            //    -> localNormal.y: 타이어 수직축(하늘), localNormal.z: 타이어 전진축(앞), localNormal.x: 타이어 횡축(우측)
            hitQx = Mathf.Atan2(localNormal.z, localNormal.y);  // 타이어 전후 오르막/내리막 경사각 (Pitch, 라디안)
            hitQy = Mathf.Atan2(-localNormal.x, localNormal.y); // 타이어 좌우 뱅크/비탈 경사각 (Roll, 라디안)
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
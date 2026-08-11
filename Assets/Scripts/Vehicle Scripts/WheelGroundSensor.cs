using UnityEngine;

/// <summary>
/// 바퀴 위치에서 지면까지의 고도(hitPointY), 기울기(Qx, Qy), 실제 거리를 감지하는 지면 센서 클래스.
/// 변경된 FMU 패치 사양에 맞춰 침투량(penetration) 대신 지면 Y 고도(gz) 및 경사도(qx, qy) 정보를 수집합니다.
/// </summary>
public class WheelGroundSensor : MonoBehaviour
{
    [Header("Sensor Settings")]
    public float wheelRadius = 0.35f;      // 타이어 반지름
    public float maxRayDistance = 2.0f;    // 레이캐스트 최대 거리

    // [Output] VehicleController 및 FMU로 전달할 지면 연산 출력값
    public float distanceFromGround; // 지면까지의 실제 거리
    public float hitPointY;          // 감지된 지면의 실제 월드 Y 좌표 (FMU gz 입력용)
    public float hitQx;              // 지면 경사도 Roll 회전 쿼터니언 x 성분
    public float hitQy;              // 지면 경사도 Pitch 회전 쿼터니언 y 성분
    public bool isGrounded;          // 지면 감지 여부

    [Header("Debug")]
    public bool enableDebugLog = true; // 디버그 로그 출력 여부

    // 레이캐스트 감지 시 무시할 레이어 마스크 (Ignore Raycast 및 UI 제외)
    private static int _targetLayerMask = -1;

    private void Awake()
    {
        // [원리]: Ignore Raycast 및 UI 레이어를 제외한 레이어 마스크를 자동 비트 연산으로 초기화
        if (_targetLayerMask == -1)
        {
            int ignoreBit = LayerMask.GetMask("Ignore Raycast", "UI");
            _targetLayerMask = ~ignoreBit;
        }
    }

    /// <summary>
    /// 차량 바퀴 위치에서 로컬 아래 방향(-transform.up)으로 레이캐스트를 발사하여 지면 정보(gz, qx, qy) 계산
    /// </summary>
    public void CalculateGroundForces()
    {
        Vector3 rayOrigin = transform.position;
        Vector3 rayDirection = -transform.up;

        RaycastHit hit;

        // 레이캐스트 수행 (자동 설정된 _targetLayerMask 사용)
        if (Physics.Raycast(rayOrigin, rayDirection, out hit, maxRayDistance, _targetLayerMask))
        {
            isGrounded = true;
            distanceFromGround = hit.distance;
            hitPointY = hit.point.y; // 실제 충돌 지면의 Y 좌표 저장 (FMU gz 연산에 활용)

            // [원리]: 수직 상방 벡터(Vector3.up)로부터 충돌 지면의 법선 벡터(hit.normal)까지의 회전 쿼터니언 계산
            Quaternion groundRotation = Quaternion.FromToRotation(Vector3.up, hit.normal);
            hitQx = groundRotation.x;
            hitQy = groundRotation.y;
        }
        else
        {
            // 지면 미감지 (공중 부양 상태)
            isGrounded = false;
            distanceFromGround = maxRayDistance;
            hitPointY = transform.position.y - maxRayDistance;

            hitQx = 0f;
            hitQy = 0f;
        }
    }

    private void FixedUpdate()
    {
        CalculateGroundForces();
    }

#if UNITY_EDITOR
    private void OnDrawGizmos()
    {
        Gizmos.color = isGrounded ? Color.green : Color.red;

        Vector3 rayDirection = -transform.up * (isGrounded ? distanceFromGround : maxRayDistance);
        Gizmos.DrawRay(transform.position, rayDirection);

        Gizmos.color = new Color(1, 1, 0, 0.3f);
        Gizmos.DrawWireSphere(transform.position, wheelRadius);
    }
#endif
}
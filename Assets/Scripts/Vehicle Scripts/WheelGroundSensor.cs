using UnityEngine;

public class WheelGroundSensor : MonoBehaviour
{
    [Header("Sensor Settings")]
    public float wheelRadius = 0.35f;      // 타이어 반지름
    public float maxRayDistance = 2.0f;    // 레이를 쏠 최대 거리 (최적화용)
    public LayerMask groundLayer;          // 지면만 인식하도록 설정 (내 차는 무시)

    // [Output] 다른 스크립트(Controller)에서 가져갈 값들
    public float distanceFromGround;// 지면까지의 실제 거리
    public float penetration;// (반지름 - 거리) : 양수면 눌림, 음수면 뜸
    public bool isGrounded;// 지면 감지 여부

    [Header("Debug")]
    public bool enableDebugLog = true; // 에디터 콘솔에서 감지된 지면 오브젝트 정보를 확인할 수 있는 디버그 토글

    // VehicleController에서 매 프레임 호출해줄 함수
    public void CalculateGroundForces()
    {
        // 내 위치에서 '로컬' 아래 방향(-transform.up)으로 레이 발사
        // (차가 뒤집어지거나 기울어지면 센서도 같이 기울어져야 하므로 Vector3.down 대신 사용)
        Vector3 rayOrigin = transform.position;
        Vector3 rayDirection = -transform.up;

        RaycastHit hit;

        // 레이캐스트 쏘기
        if (Physics.Raycast(rayOrigin, rayDirection, out hit, maxRayDistance, groundLayer))
        {
            isGrounded = true;
            distanceFromGround = hit.distance;

            // 핵심: FMU 타이어 모델은 보통 "얼마나 눌렸냐(penetration)"를 원함
            // 반지름(0.35) - 거리(0.30) = 0.05 (0.05만큼 타이어가 찌그러짐)
            penetration = wheelRadius - distanceFromGround;

            // [디버그 정보 출력]: 센서가 감지한 지면 오브젝트 이름, Layer, Hit Y 좌표 및 거리를 콘솔에 표시
            if (enableDebugLog)
            {
                Debug.Log($"[{gameObject.name}] 지면 감지 완료 -> 오브젝트: '{hit.collider.name}' (Layer: {LayerMask.LayerToName(hit.collider.gameObject.layer)}), " +
                          $"Hit Y좌표: {hit.point.y:F3}m, 거리: {hit.distance:F3}m, 침투량: {penetration:F3}m");
            }
        }
        else
        {
            // 지면이 감지되지 않음 (공중 부양)
            isGrounded = false;
            distanceFromGround = maxRayDistance;

            // 공중에 떴을 때는 penetration이 0 이하가 되어야 함 (FMU가 힘을 0으로 계산하도록)
            penetration = wheelRadius - maxRayDistance;
        }
    }
    private void FixedUpdate()
    {
        CalculateGroundForces();
    }
    // 디버깅용 (씬 뷰에서 녹색 선 확인)
#if UNITY_EDITOR
    private void OnDrawGizmos()
    {
        Gizmos.color = isGrounded ? Color.green : Color.red;

        Vector3 rayDirection = -transform.up * (isGrounded ? distanceFromGround : maxRayDistance);
        Gizmos.DrawRay(transform.position, rayDirection);

        // 타이어 크기 가이드
        Gizmos.color = new Color(1, 1, 0, 0.3f); // 반투명 노랑
        Gizmos.DrawWireSphere(transform.position, wheelRadius);
    }
#endif
}
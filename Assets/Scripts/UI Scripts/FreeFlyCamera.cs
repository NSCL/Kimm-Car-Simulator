using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// 에디트 모드 전용 수직 직하향(-90도 탑뷰) 정밀 배치 카메라.
/// 마우스 휠 줌을 100% 차단하여 휠 스크롤 시 맵이 줌인/줌아웃되는 현상을 원천 방어하며,
/// 오직 차량 Heading Yaw 각도 정렬과 WASD 키 지면 평면 이동만 제공합니다.
/// </summary>
public class FreeFlyCamera : MonoBehaviour
{
    [Header("Top-Down Fixed Movement Settings")]
    [Tooltip("WASD 지면 평면 정밀 이동 속도")]
    public float moveSpeed = 25f;
    [Tooltip("Left Shift 키 가속 배율")]
    public float boostMultiplier = 2.0f;

    private Camera cam;
    public float fixedYaw = 0f;

    private void Awake()
    {
        cam = GetComponent<Camera>();
    }

    private void Start()
    {
        AlignToVehiclePosition();
    }

    private void OnEnable()
    {
        AlignToVehiclePosition();
    }

    /// <summary>
    /// 에디트 모드 진입 시 차량 바디 상공 및 차량 Heading Yaw 회전각에 100% exact 정렬!
    /// </summary>
    public void AlignToVehiclePosition()
    {
        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            Vector3 bodyPos = vc.transform.position;
            if (vc.chassisVisualTransform != null)
            {
                bodyPos = vc.chassisVisualTransform.position;
            }
            else
            {
                MeshRenderer mr = vc.GetComponentInChildren<MeshRenderer>();
                if (mr != null) bodyPos = mr.bounds.center;
            }

            transform.position = new Vector3(bodyPos.x, bodyPos.y + 35f, bodyPos.z);
            fixedYaw = vc.transform.eulerAngles.y;
            transform.rotation = Quaternion.Euler(90f, fixedYaw, 0f);
            Debug.Log($"[FreeFlyCamera] 차량 Yaw 정렬 100% 완수 ➔ Yaw: {fixedYaw}도 | 위치: {transform.position}");
        }
        else
        {
            fixedYaw = 0f;
            transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        }
    }

    private void Update()
    {
        // 1. 오직 에디트 모드일 때만 조종 허용
        if (SimulatorManager.Instance != null && SimulatorManager.Instance.IsSimulationActive())
        {
            return;
        }

        // 2. 차량 Heading Yaw 각도에 맞춘 수직 직하향 탑뷰 100% 지속 유지
        transform.rotation = Quaternion.Euler(90f, fixedYaw, 0f);

        // 3. WASD / 방향키 기반 X-Z 지면 평면 이동 (차량 Yaw 진행방향 직통 연동)
        Vector3 planeInput = Vector3.zero;

        if (Keyboard.current != null)
        {
            if (Keyboard.current.wKey.isPressed || Keyboard.current.upArrowKey.isPressed) planeInput.z += 1f;
            if (Keyboard.current.sKey.isPressed || Keyboard.current.downArrowKey.isPressed) planeInput.z -= 1f;
            if (Keyboard.current.aKey.isPressed || Keyboard.current.leftArrowKey.isPressed) planeInput.x -= 1f;
            if (Keyboard.current.dKey.isPressed || Keyboard.current.rightArrowKey.isPressed) planeInput.x += 1f;
        }

        float currentSpeed = moveSpeed;
        if (Keyboard.current != null && Keyboard.current.leftShiftKey.isPressed)
        {
            currentSpeed *= boostMultiplier;
        }

        // 차량의 fixedYaw 회전각 기준 전후좌우 이동 Vector 계산
        Vector3 forward = Quaternion.Euler(0, fixedYaw, 0) * Vector3.forward;
        Vector3 right = Quaternion.Euler(0, fixedYaw, 0) * Vector3.right;
        Vector3 moveDir = (right * planeInput.x + forward * planeInput.z).normalized;

        transform.position += moveDir * currentSpeed * Time.unscaledDeltaTime;

        // (요청 반영) 마우스 휠 줌(Zoom) 기능 100% 완전 삭제! 
        // 휠 스크롤은 오직 차량/장애물 고스트 5도 정밀 회전에만 100% 독점 사용됩니다.
    }
}
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// 에디트 모드 전용 수직 직하향(-90도 탑뷰) 정밀 배치 카메라.
/// 시점을 수직 직하향(90도) 및 차량 Heading Yaw 각도로 정밀 고정하고,
/// WASD 키 및 방향키로 지면 평면만 미끄러지듯 이동시킵니다.
/// </summary>
public class FreeFlyCamera : MonoBehaviour
{
    [Header("Top-Down Fixed Movement Settings")]
    public float moveSpeed = 25f;
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
        }
        else
        {
            fixedYaw = 0f;
            transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        }
    }

    private void Update()
    {
        if (SimulatorManager.Instance != null && SimulatorManager.Instance.IsSimulationActive())
        {
            return;
        }

        transform.rotation = Quaternion.Euler(90f, fixedYaw, 0f);

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

        Vector3 forward = Quaternion.Euler(0, fixedYaw, 0) * Vector3.forward;
        Vector3 right = Quaternion.Euler(0, fixedYaw, 0) * Vector3.right;
        Vector3 moveDir = (right * planeInput.x + forward * planeInput.z).normalized;

        transform.position += moveDir * currentSpeed * Time.unscaledDeltaTime;
    }
}
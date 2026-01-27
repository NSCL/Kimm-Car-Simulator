using UnityEngine;
// InputSystem 네임스페이스는 없어도 되지만, 명시적으로 사용하려면 추가
// using UnityEngine.InputSystem; 

public class FreeFlyCamera : MonoBehaviour
{
    public float moveSpeed = 20f;
    public float rotateSpeed = 50f; // Input System은 감도가 다를 수 있어서 조절 필요

    void Update()
    {
        // 시뮬레이션 모드거나, 매니저가 없으면 작동 중지
        if (SimulatorManager.Instance == null || SimulatorManager.Instance.IsSimulationActive())
            return;

        // 매니저에 있는 Input 인스턴스 가져오기
        var inputs = SimulatorManager.Instance.inputActions.EditCamera;

        // 1. 이동 (WASD) - Vector2로 한번에 읽어옴
        Vector2 moveInput = inputs.Move.ReadValue<Vector2>();
        Vector3 direction = new Vector3(moveInput.x, 0, moveInput.y);
        transform.Translate(direction * moveSpeed * Time.deltaTime);

        // 2. 수직 이동 (Q, E) - 1D Axis로 읽어옴 (-1 ~ 1)
        float verticalInput = inputs.Vertical.ReadValue<float>();
        if (verticalInput != 0)
        {
            transform.Translate(Vector3.up * verticalInput * moveSpeed * Time.deltaTime);
        }

        // 3. 회전 (우클릭 하고 있을 때만)
        // IsPressed()함수로 버튼 상태 확인
        if (inputs.EnableLook.IsPressed())
        {
            Vector2 lookInput = inputs.Look.ReadValue<Vector2>();

            // Input System의 Mouse Delta는 프레임 독립적이지 않을 수 있어서 Time.deltaTime을 곱하기도 하고 안하기도 함.
            // 보통 Mouse Delta는 값이 크므로 rotateSpeed를 조절하며 감을 잡으세요.
            float rh = lookInput.x * rotateSpeed * Time.deltaTime;
            float rv = lookInput.y * rotateSpeed * Time.deltaTime;

            transform.Rotate(Vector3.up, rh, Space.World);
            transform.Rotate(Vector3.right, -rv, Space.Self);
        }
    }
}
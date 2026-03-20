using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class TelemetryManager : MonoBehaviour
{
    [Header("Managers")]
    public VehicleInputManager inputManager;
    public FMUManager fmuManager;

    [Header("Left: Sliders")]
    public Slider throttleSlider;
    public Slider steerSlider;
    public Slider brakeSlider;

    [Header("Center: Speedometer")]
    public TextMeshProUGUI speedText;
    public RectTransform needleTransform; // 속도계 바늘
    public string speedVariableName = "body_vx";
    public float maxSpeedKmh = 100f; // 계기판의 최대 속도 (맞게 수정하세요)
    public float zeroSpeedAngle = 135f; // 0km/h일 때 바늘의 Z축 회전값
    public float maxSpeedAngle = -135f; // 최대 속도일 때 바늘의 Z축 회전값

    [Header("Right: Gear Selector")]
    public RectTransform gearBox; // 슉슉 움직일 네모 박스 이미지
    // 각 기어 글자의 위치(RectTransform)를 연결할 변수들
    public RectTransform posD;
    public RectTransform posN;
    public RectTransform posR;
    public RectTransform posP;

    public float gearMoveSpeed = 15f; // 네모 박스가 이동하는 속도

    void Update()
    {
        if (inputManager == null) return;

        // 1. 좌측 슬라이더 업데이트 (에디터에서 손잡이 지운 거 확인 완료!)
        if (throttleSlider != null) throttleSlider.value = inputManager.Accel;
        if (steerSlider != null) steerSlider.value = inputManager.Steering;
        if (brakeSlider != null) brakeSlider.value = inputManager.Brake;

        // 2. 우측 기어 박스 이동 (부드러운 스무딩 적용)
        if (gearBox != null)
        {
            RectTransform targetPos = posP; // 기본값 중립

            // inputManager의 기어 상태에 따라 목표 위치 설정
            // (차량 스크립트에 맞게 숫자를 수정하세요. 보통 1=D, 0=N, -1=R, 2=P 등으로 씁니다)
            if (inputManager.Gear == 1) targetPos = posD;
            else if (inputManager.Gear == -1) targetPos = posR;
            // P 기어가 있다면 조건문 추가: else if (inputManager.Gear == 2) targetPos = posP;

            if (targetPos != null)
            {
                // 현재 위치에서 목표 위치로 슉~ 하고 부드럽게 이동
                gearBox.position = Vector3.Lerp(gearBox.position, targetPos.position, Time.deltaTime * gearMoveSpeed);
            }
        }

        // 3. 중앙 속도계 (텍스트 + 바늘)
        if (fmuManager != null && speedText != null && needleTransform != null)
        {
            // FMU에서 속도 가져오기 (변수명 'body_vx' 맞으시죠?)
            float speedMs = (float)fmuManager.GetValue(speedVariableName);
            float speedKmh = Mathf.Abs(speedMs * 3.6f);

            // 텍스트 업데이트 (소수점 버림)
            speedText.text = Mathf.RoundToInt(speedKmh).ToString();

            // 바늘 회전 계산 (0.0 ~ 1.0 비율로 변환)
            float speedRatio = Mathf.Clamp01(speedKmh / maxSpeedKmh);

            // 비율에 맞춰 바늘의 각도 계산 후 적용
            float targetAngle = Mathf.Lerp(zeroSpeedAngle, maxSpeedAngle, speedRatio);
            needleTransform.localRotation = Quaternion.Euler(0, 0, targetAngle);
        }
    }
}
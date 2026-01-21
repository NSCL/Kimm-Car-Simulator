using System;
using UnityEngine;
using UnityEngine.InputSystem;

public class VehicleInputManager : MonoBehaviour
{
    private VehicleInputControls _inputActions;

    // 기어 상태 정의 (Inspector에서 드롭다운으로 보임)
    public enum GearState { Park, Reverse, Neutral, Drive }

    [Header("Gear Status")]
    [SerializeField] private GearState currentGear = GearState.Neutral; // 기어 상태
    private bool isUsingKeyboard = false; // 현재 키보드 모드인지 확인용

    [Header("Current Value")]
    [SerializeField] private float currentSteering;
    [SerializeField] private float currentAccel;
    [SerializeField] private float currentBrake;

    [Header("Keyboard Input Settings")]
    [SerializeField] private float steeringSpeed = 2.0f;
    [SerializeField] private float pedalSpeed = 3.0f;
    [SerializeField] private float returnSpeed = 5.0f;

    public event Action OnResetTriggered;
    // 외부 공개 프로퍼티
    public float Steering => currentSteering;
    public float Accel => currentAccel;
    public float Brake => currentBrake;
    public int Gear => (int)currentGear; // 필요시 정수로 변환

    // 각 입력별로 마지막 사용 장치가 키보드였는지 기억하는 변수들
    private bool _steerWasKeyboard = false;
    private bool _accelWasKeyboard = false;
    private bool _brakeWasKeyboard = false;
    public void SetInputActive(bool isActive)
    {
        if (isActive)
        {
            // 1. 켜기: 다시 Update가 돌게 함
            this.enabled = true;
        }
        else
        {
            // 2. 끄기 전 안전장치: 밟고 있던 엑셀/브레이크 강제 초기화
            // (이거 안 하면 엑셀 1인 상태로 꺼져서 차가 계속 나갑니다)
            currentSteering = 0f;
            currentAccel = 0f;
            currentBrake = 0f; // 또는 1f (완전 정지)

            // 3. 끄기: 이제 Update가 멈추고, OnDisable이 실행되어 Input System도 쉬게 됨
            this.enabled = false;
        }
    }
    private void Awake() => _inputActions = new VehicleInputControls();
    private void OnEnable()
    {
        _inputActions.Enable();

        // 기어 변속 이벤트 연결
        _inputActions.Vehicle.GearDrive.performed += _ => ShiftGear(GearState.Drive);
        _inputActions.Vehicle.GearReverse.performed += _ => ShiftGear(GearState.Reverse);
        _inputActions.Vehicle.ResetPosition.performed += _ => OnResetTriggered?.Invoke();
    }

    private void OnDisable() => _inputActions.Disable();

    private void Update()
    {
        // 각 입력 처리
        currentSteering = ProcessAxis(_inputActions.Vehicle.Steering, currentSteering, ref _steerWasKeyboard, steeringSpeed);
        currentAccel = ProcessAxis(_inputActions.Vehicle.Accel, currentAccel, ref _accelWasKeyboard, pedalSpeed);
        currentBrake = ProcessAxis(_inputActions.Vehicle.Brake, currentBrake, ref _brakeWasKeyboard, pedalSpeed * 2f); // 브레이크는 좀 더 빠르게

        // 디버깅용: 전체적으로 키보드 쓰고 있는지 표시
        isUsingKeyboard = _steerWasKeyboard || _accelWasKeyboard || _brakeWasKeyboard;
    }

    // [핵심 로직] 입력을 처리하고 값을 반환하는 함수
    private float ProcessAxis(InputAction action, float currentVal, ref bool wasKeyboard, float sensitive)
    {
        float rawVal = action.ReadValue<float>();

        // 1. 현재 입력이 어디서 왔는지 판별
        if (action.activeControl != null)
        {
            // 입력 장치가 키보드라면 -> 확실히 키보드 모드로 전환
            if (action.activeControl.device is Keyboard)
            {
                wasKeyboard = true;
            }
            // 입력값이 유의미하게 크고(노이즈 0.1 제외), 키보드가 아니라면 -> 휠 모드로 전환
            else if (Mathf.Abs(rawVal) > 0.1f)
            {
                wasKeyboard = false;
            }
            // *중요*: 입력이 0이거나 미세할 때는 상태를 바꾸지 않고 '마지막 상태'를 유지합니다.
            // 그래야 키보드를 뗐을 때(입력 0)도 wasKeyboard가 true로 유지되어 returnSpeed가 작동합니다.
        }

        // 2. 모드에 따른 값 처리
        if (wasKeyboard)
        {
            // 키보드 모드: MoveTowards로 부드럽게 증감
            // 입력이 있으면 sensitive 속도, 없으면(복귀) returnSpeed 사용
            float targetSpeed = (rawVal != 0) ? sensitive : returnSpeed;
            return Mathf.MoveTowards(currentVal, rawVal, targetSpeed * Time.deltaTime);
        }
        else
        {
            // 휠 모드: 입력값 직결 (Direct)
            return rawVal;
        }
    }

    private void ShiftGear(GearState target)
    {
        currentGear = target;
        // 여기에 기어 변경 효과음이나 UI 업데이트 로직 추가 가능
    }
}
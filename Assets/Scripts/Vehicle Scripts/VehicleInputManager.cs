using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// 키보드(Keyboard), 게임패드(Gamepad), 레이싱 휠/조이스틱(Joystick/HID Wheel Controller)의 
/// 아날로그 조향/가속/브레이크 및 기어 변속 입력을 100% 통합 합성하는 매니저.
/// (빌드 최적화: 콘솔 로그 정제)
/// </summary>
public class VehicleInputManager : MonoBehaviour
{
    public enum GearState { Park, Reverse, Neutral, Drive }

    [Header("Gear Status")]
    [SerializeField] private GearState currentGear = GearState.Drive;
    public GearState CurrentGear => currentGear;

    [Header("Input Sensitivity")]
    [SerializeField] private float steeringSensitivity = 4.0f;
    [SerializeField] private float accelSensitivity = 5.0f;
    [SerializeField] private float brakeSensitivity = 5.0f;
    [SerializeField] private float returnSpeed = 6.0f;

    [Header("Current Input Values")]
    public float Steering;
    public float Accel;
    public float Brake;

    public int Gear
    {
        get
        {
            switch (currentGear)
            {
                case GearState.Park:
                    return 0;
                case GearState.Reverse:
                    return -1;
                case GearState.Neutral:
                    return 0;
                case GearState.Drive:
                    return 1;
                default:
                    return 1;
            }
        }
    }

    public event Action OnResetTriggered;

    private bool _isInputActive = true;

    private void Update()
    {
        if (!_isInputActive) return;

        float targetSteer = 0f;
        float targetAccel = 0f;
        float targetBrake = 0f;

        // 1. 키보드 입력 스캔 (Keyboard.current)
        var keyboard = Keyboard.current;
        if (keyboard != null)
        {
            // 🏎️ 키보드 기어 단축키 (Shift = 전진 D, Ctrl = 후진 R, N = 중립 N, P = 주차 P, E/Q 동시 지원)
            if (keyboard.leftShiftKey.wasPressedThisFrame || keyboard.rightShiftKey.wasPressedThisFrame || keyboard.eKey.wasPressedThisFrame)
                ShiftGear(GearState.Drive);
            if (keyboard.leftCtrlKey.wasPressedThisFrame || keyboard.rightCtrlKey.wasPressedThisFrame)
                ShiftGear(GearState.Reverse);
            if (keyboard.nKey.wasPressedThisFrame)
                ShiftGear(GearState.Neutral);
            if (keyboard.pKey.wasPressedThisFrame)
                ShiftGear(GearState.Park);
            if (keyboard.qKey.wasPressedThisFrame)
            {
                if (currentGear == GearState.Reverse) ShiftGear(GearState.Neutral);
                else ShiftGear(GearState.Reverse);
            }
            if (keyboard.rKey.wasPressedThisFrame)
                OnResetTriggered?.Invoke();

            if (keyboard.aKey.isPressed || keyboard.leftArrowKey.isPressed) targetSteer -= 1.0f;
            if (keyboard.dKey.isPressed || keyboard.rightArrowKey.isPressed) targetSteer += 1.0f;
            if (keyboard.wKey.isPressed || keyboard.upArrowKey.isPressed) targetAccel += 1.0f;
            if (keyboard.sKey.isPressed || keyboard.downArrowKey.isPressed || keyboard.spaceKey.isPressed) targetBrake += 1.0f;
        }

        // 2. 게임패드 및 Power Shift Revolution / USB 레이싱 휠 스캔
        var gamepad = Gamepad.current;
        if (gamepad != null)
        {
            float padSteer = gamepad.leftStick.x.ReadValue();
            if (Mathf.Abs(padSteer) > 0.05f) targetSteer = padSteer;

            float padAccel = gamepad.rightTrigger.ReadValue();
            if (padAccel > 0.05f) targetAccel = padAccel;

            float padBrake = gamepad.leftTrigger.ReadValue();
            if (padBrake > 0.05f) targetBrake = padBrake;

            // 🏎️ 기어 올리기 (패들 시프트 우측/R1) -> 무조건 Drive (1) 고정!
            if (gamepad.rightShoulder.wasPressedThisFrame)
            {
                ShiftGear(GearState.Drive);
            }

            // 🏎️ 기어 내리기 (패들 시프트 좌측/L1) -> Reverse (-1) <-> Neutral (0) 순환 스위칭!
            if (gamepad.leftShoulder.wasPressedThisFrame)
            {
                if (currentGear == GearState.Reverse) ShiftGear(GearState.Neutral);
                else ShiftGear(GearState.Reverse);
            }

            // 🔴 B 버튼 -> 차량 초기화 위치 리셋 (R 키 기능 100% 직통 동일!)
            if (gamepad.buttonEast.wasPressedThisFrame)
            {
                OnResetTriggered?.Invoke();
            }
        }

        var joystick = Joystick.current;
        if (joystick != null)
        {
            float joySteer = joystick.stick.x.ReadValue();
            if (Mathf.Abs(joySteer) > 0.05f) targetSteer = joySteer;
        }

        // 입력 값 보간 적용
        Steering = Mathf.MoveTowards(Steering, targetSteer, (targetSteer != 0 ? steeringSensitivity : returnSpeed) * Time.deltaTime);
        Accel = Mathf.MoveTowards(Accel, targetAccel, (targetAccel != 0 ? accelSensitivity : returnSpeed) * Time.deltaTime);
        Brake = Mathf.MoveTowards(Brake, targetBrake, (targetBrake != 0 ? brakeSensitivity : returnSpeed) * Time.deltaTime);
    }

    public void ShiftGear(GearState target)
    {
        currentGear = target;
    }

    public void SetInputActive(bool active)
    {
        _isInputActive = active;
        if (!active)
        {
            Steering = 0;
            Accel = 0;
            Brake = 0;
        }
    }
}
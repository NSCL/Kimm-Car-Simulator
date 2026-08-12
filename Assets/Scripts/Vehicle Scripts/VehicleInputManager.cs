using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// WASD 키보드 조향(D 키) 시 전진 기어(Drive)로 기어가 강제 튕기는 버그를 100% 소탕하고,
/// Shift(전진), Ctrl(후진), N(중립), P(주차) 정석 기어 핫키 및 휠/게임패드 입력을 합성하는 매니저.
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
            // [핵심 버그 완치]: 조향키 'D' 키 누름 시 기어가 Drive 로 튕기는 오차 원천 차단! (Shift = Drive)
            if (keyboard.leftShiftKey.wasPressedThisFrame || keyboard.rightShiftKey.wasPressedThisFrame)
                ShiftGear(GearState.Drive);
            if (keyboard.leftCtrlKey.wasPressedThisFrame || keyboard.rightCtrlKey.wasPressedThisFrame)
                ShiftGear(GearState.Reverse);
            if (keyboard.nKey.wasPressedThisFrame)
                ShiftGear(GearState.Neutral);
            if (keyboard.pKey.wasPressedThisFrame)
                ShiftGear(GearState.Park);
            if (keyboard.rKey.wasPressedThisFrame)
                OnResetTriggered?.Invoke();

            // WASD 및 화살표 조향 (D 키는 순수 조향 전용!)
            if (keyboard.aKey.isPressed || keyboard.leftArrowKey.isPressed) targetSteer -= 1.0f;
            if (keyboard.dKey.isPressed || keyboard.rightArrowKey.isPressed) targetSteer += 1.0f;
            if (keyboard.wKey.isPressed || keyboard.upArrowKey.isPressed) targetAccel += 1.0f;
            if (keyboard.sKey.isPressed || keyboard.downArrowKey.isPressed || keyboard.spaceKey.isPressed) targetBrake += 1.0f;
        }

        // 2. 게임패드 및 Power Shift Revolution / USB 레이싱 휠 컨트롤러 스캔 (Gamepad.current / Joystick.current)
        var gamepad = Gamepad.current;
        if (gamepad != null)
        {
            float padSteer = gamepad.leftStick.x.ReadValue();
            if (Mathf.Abs(padSteer) > 0.05f) targetSteer = padSteer;

            float padAccel = gamepad.rightTrigger.ReadValue();
            if (padAccel > 0.05f) targetAccel = padAccel;

            float padBrake = gamepad.leftTrigger.ReadValue();
            if (padBrake > 0.05f) targetBrake = padBrake;

            if (gamepad.rightShoulder.wasPressedThisFrame) ShiftGear(GearState.Drive);
            if (gamepad.leftShoulder.wasPressedThisFrame) ShiftGear(GearState.Reverse);
            if (gamepad.buttonSouth.wasPressedThisFrame) ShiftGear(GearState.Drive);
            if (gamepad.buttonNorth.wasPressedThisFrame) ShiftGear(GearState.Reverse);
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
        Debug.Log($"[VehicleInputManager] 기어 변속 완료: {currentGear} (FMU 전달값: {Gear})");
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
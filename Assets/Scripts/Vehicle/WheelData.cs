using UnityEngine;

/// <summary>
/// 각 바퀴(FL, FR, RL, RR)의 Transform, 지면 센서, FMU 입출력 핀 매핑 정보를 관리하는 데이터 구조체
/// </summary>
[System.Serializable]
public class WheelData
{
    [Header("1. Identity")]
    public string id; // "FL", "FR", "RL", "RR"

    [Header("2. Objects")]
    public Transform wheelRoot;   // 바퀴 회전/위치 루트 Transform
    public Transform wheelVisual; // 바퀴 비주얼 메쉬 Transform
    public WheelGroundSensor sensor;

    [Header("3. Inputs")]
    [FMUVariable(true)] public string var_WheelOmega_In; // 각속도 입력
    [FMUVariable(true)] public string var_GroundDist_In; // 지면 상대 고도(gz) 입력
    [FMUVariable(true)] public string var_GroundQx_In;   // 지면 경사도 회전 Qx 입력
    [FMUVariable(true)] public string var_GroundQy_In;   // 지면 경사도 회전 Qy 입력

    [Header("4. Outputs - Position")]
    [FMUVariable] public string var_WheelPos_X;
    [FMUVariable] public string var_WheelPos_Y;
    [FMUVariable] public string var_WheelPos_Z;

    [Header("5. Outputs - Rotation (Quaternion)")]
    [FMUVariable] public string var_WheelRot_X;
    [FMUVariable] public string var_WheelRot_Y;
    [FMUVariable] public string var_WheelRot_Z;
    [FMUVariable] public string var_WheelRot_W;

    [Header("6. Outputs - Spin")]
    [FMUVariable] public string var_WheelSpin_Out; // 바퀴 자전 각도 출력 (rad)
}
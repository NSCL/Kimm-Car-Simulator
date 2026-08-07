using UnityEngine;

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
    [FMUVariable(true)] public string var_GroundDist_In; // Penetration / gz 입력
    [FMUVariable(true)] public string var_GroundQx_In;   // 지면 패치 롤/피치 회전 Qx 입력
    [FMUVariable(true)] public string var_GroundQy_In;   // 지면 패치 롤/피치 회전 Qy 입력

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
    [FMUVariable] public string var_WheelSpin_Out; // fmi_Angle_Out
}
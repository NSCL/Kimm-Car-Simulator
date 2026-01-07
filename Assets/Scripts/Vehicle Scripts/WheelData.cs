using UnityEngine;

[System.Serializable]
public class WheelData
{
    [Header("1. Identity")]
    public string id; // "FL", "FR" 등

    [Header("2. Objects")]
    public Transform wheelRoot;   // [더미]
    public Transform wheelVisual; // [메쉬]
    public WheelGroundSensor sensor;

    [Header("3. Inputs")]
    [FMUVariable(true)] public string var_WheelOmega_In; // 각속도 입력
    [FMUVariable(true)] public string var_GroundDist_In; // Penetration 입력

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
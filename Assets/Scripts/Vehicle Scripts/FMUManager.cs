using UnityEngine;
using System.Collections.Generic;

// [중요] 이 클래스는 FMUImporter가 쓰는 ScalarVariable과는 별개로
// 우리 시뮬레이터가 실제로 값을 수정하고 놀 런타임용 변수입니다.
[System.Serializable]
public class RuntimeFMUVariable
{
    public string name;      // 변수 이름 (steering 등)
    public float value;      // 현재 값
    public string causality; // input, output, local, parameter 등
}

public class FMUManager : MonoBehaviour
{
    [HideInInspector]
    public string selectedFMUName;

    // 인스펙터에 보여질 변수 리스트
    public List<RuntimeFMUVariable> variables = new List<RuntimeFMUVariable>();

    // 외부(차량 물리 등)에서 값을 가져갈 때 쓰는 함수
    public float GetValue(string varName)
    {
        var v = variables.Find(x => x.name == varName);
        return v != null ? v.value : 0f;
    }

    // 외부에서 값을 넣어줄 때 쓰는 함수 (Input)
    public void SetValue(string varName, float value)
    {
        var v = variables.Find(x => x.name == varName);
        if (v != null) v.value = value;
    }
}
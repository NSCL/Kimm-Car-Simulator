using UnityEngine;
using System.Collections.Generic;
using FMI2;

// [중요] 이 클래스는 FMUImporter가 쓰는 ScalarVariable과는 별개로
// 우리 시뮬레이터가 실제로 값을 수정하고 놀 런타임용 변수입니다.
[System.Serializable]
public class RuntimeFMUVariable
{
    public string name;      // 변수 이름 (steering 등)
    public double value;      // 현재 값
    public string causality; // input, output, local, parameter 등
}

public class FMUManager : MonoBehaviour
{
    [HideInInspector]
    public string selectedFMUName;

    // 인스펙터에 보여질 변수 리스트
    public List<RuntimeFMUVariable> variables = new List<RuntimeFMUVariable>();

    //실제 시뮬레이션 엔진
    private FMU fmu;

    private void Start()
    {
        if(string.IsNullOrEmpty(selectedFMUName))
        {
            Debug.LogError("FMU is Null or Empty.");
            return;
        }

        try
        {
            fmu = new FMU(selectedFMUName, this.name);
            fmu.Reset();
            fmu.SetupExperiment(Time.fixedTimeAsDouble);
            fmu.EnterInitializationMode();
            fmu.ExitInitializationMode();
            Debug.Log($"[FMUManager]{selectedFMUName} Set up finished.");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"[FMU Init Error]{e.Message}");
        }
    }

    private void OnDestroy()
    {
        if (fmu != null) 
        {
            fmu.Dispose();
            fmu= null;
        }
    }

    // 외부에서 값을 넣어줄 때 쓰는 함수 (Input)
    public void SetValue(string varName, double value)
    {
        var v = variables.Find(x => x.name == varName);
        if (v != null) v.value = value;

        if(fmu != null)
        {
            fmu.SetReal(varName, (double)value);
        }
    }

    // 외부(차량 물리 등)에서 값을 가져갈 때 쓰는 함수
    public double GetValue(string varName)
    {
        double result = 0.0f;
        if (fmu != null) 
        {
            result=(double)fmu.GetReal(varName);
        }
        else
        {
            var v = variables.Find(x => x.name == varName);
            if(v != null) result = v.value;
        }

        var targetVar = variables.Find(x => x.name==varName);
        if (targetVar != null) targetVar.value = result;

        return result;
    }

    public void DoStep()
    {
        if(fmu != null)
        {
            fmu.DoStep(Time.timeAsDouble, (double)Time.fixedDeltaTime);
        }
    }
}
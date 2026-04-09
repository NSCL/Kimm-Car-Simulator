using UnityEngine;
using System.Collections.Generic;
using FMI2;
using System.Diagnostics;

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
    public double stepSize = 0.001;
    //  [추가됨] 성능 폭발 최적화: 매 프레임마다 리스트를 뒤지지 않도록 딕셔너리로 관리합니다.
    private Dictionary<string, RuntimeFMUVariable> varDict = new Dictionary<string, RuntimeFMUVariable>();

    // 실제 시뮬레이션 엔진
    private FMU fmu;

    private double currentTime = 0.0;

    private void Awake()
    {
        // 시작하기 전에, 인스펙터에 있는 변수들을 빛의 속도로 찾을 수 있게 딕셔너리에 담아둡니다.
        foreach (var v in variables)
        {
            varDict[v.name] = v;
        }
    }

    private void Start()
    {
        if (string.IsNullOrEmpty(selectedFMUName))
        {
            UnityEngine.Debug.LogError("FMU is Null or Empty.");
            return;
        }

        try
        {
            ResetFMU();
        }
        catch (System.Exception e)
        {
            UnityEngine.Debug.LogError($"[FMU Init Error]{e.Message}");
        }
    }

    private void OnDestroy()
    {
        if (fmu != null)
        {
            fmu.Dispose();
            fmu = null;
        }
    }

    public void ResetFMU()
    {
        //  [핵심 버그 수정됨] VehicleController에서 Reset을 부를 때마다 기존 C++ 메모리가 터지는 걸 막습니다!
        if (fmu != null)
        {
            fmu.Dispose(); // 기존 메모리 안전하게 해제
            fmu = null;
        }

        currentTime = 0.0;
        fmu = new FMU(selectedFMUName, this.name);
        fmu.Reset();
        fmu.SetupExperiment(Time.fixedTimeAsDouble);
        fmu.EnterInitializationMode();
        fmu.ExitInitializationMode();
        UnityEngine.Debug.Log($"[FMUManager] {selectedFMUName} Set up finished.");
    }

    // 외부에서 값을 넣어줄 때 쓰는 함수 (Input)
    public void SetValue(string varName, double value)
    {
        //  [수정됨] 매 프레임 쓰레기를 만들던 Find 함수 대신, 딕셔너리에서 바로 꺼냅니다.
        if (varDict.TryGetValue(varName, out RuntimeFMUVariable v))
        {
            v.value = value;
        }

        if (fmu != null)
        {
            fmu.SetReal(varName, value);
        }
    }

    // 외부(차량 물리 등)에서 값을 가져갈 때 쓰는 함수
    public double GetValue(string varName)
    {
        double result = 0.0;

        if (fmu != null)
        {
            result = fmu.GetReal(varName);
        }
        else
        {
            // FMU가 없을 때도 딕셔너리에서 안전하게 찾습니다.
            if (varDict.TryGetValue(varName, out RuntimeFMUVariable v))
            {
                result = v.value;
            }
        }

        // 인스펙터 업데이트용
        if (varDict.TryGetValue(varName, out RuntimeFMUVariable targetVar))
        {
            targetVar.value = result;
        }

        return result;
    }

    public void DoStep()
    {
        if (fmu != null)
        {
            fmu.DoStep(currentTime, (double)Time.fixedDeltaTime);
            currentTime += (double)Time.fixedDeltaTime;
        }
        //if (fmu != null)
        //{
        //    double cleanStep = 0.001;

        //    Stopwatch sw = new Stopwatch(); // 초시계 준비
        //    sw.Start(); // 측정 시작

        //    fmu.DoStep(currentTime, cleanStep); // 실제 C++ DLL 연산

        //    sw.Stop(); // 측정 종료

        //    // 1번 계산하는 데 현실에서 몇 초 걸렸는지 로그 출력
        //    UnityEngine.Debug.Log($"1스텝 계산 소요 현실 시간: {sw.Elapsed.TotalSeconds:F5} 초");

        //    currentTime += cleanStep;
        //}
    }
}
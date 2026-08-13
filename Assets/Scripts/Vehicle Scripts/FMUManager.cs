using UnityEngine;
using System.Collections.Generic;
using FMI2;

/// <summary>
/// FMU 런타임 변수 및 파라미터 매핑을 위한 데이터 구조체
/// ModelDescription에서 추출한 이름, 값, causality(input, output, parameter 등) 정보를 유지합니다.
/// </summary>
[System.Serializable]
public class RuntimeFMUVariable
{
    public string name;      // 변수/파라미터 이름 (예: SteerInput, Veh_BodyMass)
    public double value;     // 변수/파라미터 값
    public string causality; // 변수 속성 (input, output, local, parameter 등)
}

/// <summary>
/// FMU 실행 및 런타임 입출력/파라미터 제어를 총괄하는 유니티 MonoBehaviour 매니저 클래스
/// </summary>
public class FMUManager : MonoBehaviour
{
    [HideInInspector]
    public string selectedFMUName;

    // 인스펙터 및 런타임에 관리되는 FMU 변수/파라미터 리스트
    public List<RuntimeFMUVariable> variables = new List<RuntimeFMUVariable>();
    public double stepSize = 0.001;

    // 변수명으로 빠른 조회를 위한 딕셔너리
    private Dictionary<string, RuntimeFMUVariable> varDict = new Dictionary<string, RuntimeFMUVariable>();

    // C++ DLL FMU 인스턴스 객체
    private FMU fmu;

    private double currentTime = 0.0;

    private void Awake()
    {
        // 씬 시작 시 변수 리스트를 딕셔너리에 매핑하여 빠른 조회 보장
        foreach (var v in variables)
        {
            varDict[v.name] = v;
        }
    }

    private void Start()
    {
        if (string.IsNullOrEmpty(selectedFMUName))
        {
            UnityEngine.Debug.LogError("FMU Name is Null or Empty.");
            return;
        }

        try
        {
            // VehicleConfigManager가 존재하면 로드된 JSON 파라미터 업데이트
            if (VehicleConfigManager.Instance != null && VehicleConfigManager.Instance.loadedParameters.Count > 0)
            {
                foreach (var kvp in VehicleConfigManager.Instance.loadedParameters)
                {
                    var v = variables.Find(varItem => varItem.name == kvp.Key);
                    if (v != null) v.value = kvp.Value;
                }
            }

            ResetFMU();
        }
        catch (System.Exception e)
        {
            UnityEngine.Debug.LogError($"[FMU Init Error] {e.Message}");
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

    /// <summary>
    /// FMU 인스턴스를 재설정하고 초기화 모드에서 설정된 파라미터(Mass, Wheelbase 등)를 FMU C++ DLL에 주입합니다.
    /// </summary>
    public void ResetFMU()
    {
        if (fmu != null)
        {
            fmu.Dispose();
            fmu = null;
        }

        currentTime = 0.0;
        fmu = new FMU(selectedFMUName, this.name);
        fmu.Reset();
        fmu.SetupExperiment(Time.fixedTimeAsDouble);

        // FMU 초기화 모드 진입
        fmu.EnterInitializationMode();

        // [핵심 로직] VehicleConfigManager의 최근 로드 파라미터가 있다면 우선 갱신
        if (VehicleConfigManager.Instance != null && VehicleConfigManager.Instance.loadedParameters.Count > 0)
        {
            foreach (var kvp in VehicleConfigManager.Instance.loadedParameters)
            {
                var v = variables.Find(varItem => varItem.name == kvp.Key);
                if (v != null) v.value = kvp.Value;
            }
        }

        // [주의]: EnterInitializationMode와 ExitInitializationMode 사이에서는
        // 오직 causality가 "parameter"인 구조 파라미터만 주입해야 합니다.
        // input 변수(FL_gz, Throttle 등)를 초기화 모드에서 0으로 덮어쓰면 지면 고도 오차로 진동이 발생합니다.
        foreach (var v in variables)
        {
            if (v.causality == "parameter")
            {
                fmu.SetReal(v.name, v.value);
            }
        }

        // FMU 초기화 모드 종료 (계산 준비 완료)
        fmu.ExitInitializationMode();
    }

    /// <summary>
    /// FMU 입력(Input) 또는 파라미터(Parameter) 값 설정
    /// </summary>
    public void SetValue(string varName, double value)
    {
        if (varDict.TryGetValue(varName, out RuntimeFMUVariable v))
        {
            v.value = value;
        }

        if (fmu != null)
        {
            fmu.SetReal(varName, value);
        }
    }

    /// <summary>
    /// FMU 출력(Output) 또는 현재 변수 값 조회
    /// </summary>
    public double GetValue(string varName)
    {
        double result = 0.0;

        if (fmu != null)
        {
            result = fmu.GetReal(varName);
        }
        else
        {
            if (varDict.TryGetValue(varName, out RuntimeFMUVariable v))
            {
                result = v.value;
            }
        }

        if (varDict.TryGetValue(varName, out RuntimeFMUVariable targetVar))
        {
            targetVar.value = result;
        }

        return result;
    }

    /// <summary>
    /// FMU 고정 시간 스텝(Fixed Delta Time) 연산 수행
    /// </summary>
    public void DoStep()
    {
        if (fmu != null)
        {
            fmu.DoStep(currentTime, (double)Time.fixedDeltaTime);
            currentTime += (double)Time.fixedDeltaTime;
        }
    }
}
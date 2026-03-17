using System;
using System.Collections.Generic;
using UnityEngine;

public class VehicleTelemetry : MonoBehaviour
{
    [Header("References")]
    public VehicleInputManager inputManager;
    public FMUManager fmuManager;

    // 핵심 1: UI 드롭다운에 던져줄 예쁜 이름표 목록
    [HideInInspector]
    public List<string> availableDataNames = new List<string>();

    // 핵심 2: 이름표를 주면, 즉시 값을 반환하는 자판기 (O(1) 속도로 매우 빠름)
    private Dictionary<string, Func<float>> dataProviders = new Dictionary<string, Func<float>>();

    private void Start()
    {
        InitializeTelemetry();
    }

    // 차트 매니저가 부를 수도 있으니 public으로 열어둡니다.
    public void InitializeTelemetry()
    {
        if (dataProviders.Count > 0) return; // 이미 세팅됐으면 패스

        dataProviders.Clear();
        availableDataNames.Clear();

        // 1. 유니티 입력 데이터 '자동' 등록
        if (inputManager != null)
        {
            RegisterData("Input: Accel", () => inputManager.Accel);
            RegisterData("Input: Brake", () => inputManager.Brake);
            RegisterData("Input: Steering", () => inputManager.Steering);
            RegisterData("Input: Gear", () => inputManager.Gear);
        }

        // 2. FMUManager의 variables 리스트를 싹 뒤져서 '자동' 등록
        if (fmuManager != null && fmuManager.variables != null)
        {
            foreach (var fmuVar in fmuManager.variables)
            {
                // C# 클로저(Closure) 이슈 방지를 위해 지역 변수에 복사
                string varName = fmuVar.name;

                // "FMU: body_vx" 라는 이름표로, fmuManager.GetValue()를 실행하는 함수를 통째로 딕셔너리에 저장
                RegisterData($"FMU: {varName}", () => (float)fmuManager.GetValue(varName));
            }
        }

        Debug.Log($"[Telemetry] 총 {availableDataNames.Count}개의 데이터를 수집했습니다.");
    }

    // 딕셔너리와 리스트에 동시에 꽂아넣는 헬퍼 함수
    private void RegisterData(string displayName, Func<float> providerFunction)
    {
        dataProviders[displayName] = providerFunction;
        availableDataNames.Add(displayName);
    }

    // 외부(ChartModule)에서 이 함수 하나만 부르면 모든 데이터가 튀어나옵니다!
    public float GetValue(string dataName)
    {
        if (dataProviders.TryGetValue(dataName, out Func<float> provider))
        {
            return provider.Invoke(); // 연결된 함수 실행해서 값 반환
        }
        return 0f;
    }
}
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

    // [원리]: 외부(ChartModule)에서 이 함수 하나만 부르면 프레임 캐싱된 빠른 데이터가 반환됩니다.
    public float GetValue(string dataName)
    {
        return GetDataValue(dataName);
    }
    private Dictionary<string, float> cachedValues = new Dictionary<string, float>();
    private int lastCachedFrame = -1;

    // [원리]: 동일한 프레임(Time.frameCount) 내에서 차트 여러 개가 동시에 동일한 텔레메트리 데이터(예: FMU: body_vx)를 요구할 때,
    // 매번 FMU 딕셔너리 탐색 및 람다 함수를 호출하지 않고 첫번째 호출 결과를 프레임 캐시에 저장하여 반환합니다.
    // 이를 통해 차트 개수가 N개로 늘어나도 FMU 데이터 조회 비용을 O(N)에서 O(1)로 획기적으로 줄여 CPU 지연을 완벽히 방지합니다.
    public float GetDataValue(string displayName)
    {
        int currentFrame = Time.frameCount;
        if (currentFrame != lastCachedFrame)
        {
            cachedValues.Clear();
            lastCachedFrame = currentFrame;
        }

        if (cachedValues.TryGetValue(displayName, out float cachedVal))
        {
            return cachedVal;
        }

        if (dataProviders.TryGetValue(displayName, out var provider))
        {
            float val = provider();
            cachedValues[displayName] = val;
            return val;
        }
        return 0f;
    }
}
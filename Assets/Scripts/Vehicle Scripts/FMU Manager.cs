using UnityEngine;

public class FMUManager : MonoBehaviour
{
    // 드롭다운에서 선택한 FMU 폴더 이름이 여기에 저장됩니다.
    // 인스펙터에서는 드롭다운으로 선택할 거라 텍스트 입력창은 숨깁니다.
    [HideInInspector]
    public string selectedFMUName;

    [Header("Other Settings")]
    public float simulationSpeed = 1.0f; // 다른 변수 테스트용

    // 현재 선택된 FMU가 뭔지 확인하는 테스트 함수
    private void Start()
    {
        if (string.IsNullOrEmpty(selectedFMUName))
        {
            Debug.LogWarning("FMU가 선택되지 않았습니다.");
        }
        else
        {
            Debug.Log($"시뮬레이션 시작: {selectedFMUName} 로드 중...");
        }
    }
}
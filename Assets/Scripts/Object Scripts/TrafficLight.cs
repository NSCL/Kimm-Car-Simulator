using System.Collections.Generic;
using UnityEngine;
using static UnityEditorInternal.VersionControl.ListControl;

public class TrafficLight : MonoBehaviour
{
    public enum LightState
    {
        Red,
        Yellow,
        Left,
        Green,
        GreenAndLeft, // 녹색+좌회전 동시 신호 대응용
        AllOff        // 전체 소등 (필요 시)
    }
    [System.Serializable]
    public struct LightGroup
    {
        public LightState state;
        [Tooltip("이 상태가 되었을 때 활성화(On)할 전구 오브젝트들을 등록하세요.")]
        public GameObject[] activeObjects;
    }

    [System.Serializable]
    public struct StateSequence
    {
        public LightState state;
        [Tooltip("이 상태를 유지할 시간(초)")]
        public float duration;
    }

    [Header("신호등 상태별 오브젝트 설정")]
    [SerializeField]
    private List<LightGroup> lightGroups = new List<LightGroup>();

    [Header("독립 자동 주행 설정")]
    [Tooltip("체크하면 다른 컨트롤러 없이 이 신호등 스스로 정해진 시간표대로 루프를 돕니다.")]
    [SerializeField] private bool useSequence = true;

    [Tooltip("스스로 돌 때 순환할 신호 시퀀스와 지속 시간입니다.")]
    [SerializeField] private List<StateSequence> sequenceList = new List<StateSequence>();

    [Header("시뮬레이션 시간 배율")]
    [Tooltip("시뮬레이션 시간 속도 조절용 배율 (높을수록 신호가 빠르게 바뀝니다.)")]
    [Range(0.1f, 10f)]
    public float timeScale = 1.0f;

    // 현재 상태 및 타이머 변수들
    public LightState CurrentState { get; private set; } = LightState.AllOff;
    private int currentSequenceIndex = 0;
    private float timer = 0f;

    private void Awake()
    {
        // 시작할 때 최초 상태 적용
        if (useSequence && sequenceList.Count > 0)
        {
            currentSequenceIndex = 0;
            ApplyStateAndResetTimer(sequenceList[currentSequenceIndex].state);
        }
        else
        {
            SetState(LightState.AllOff);
        }
    }

    private void Update()
    {
        // 독립 자동 주행 모드가 아닐 때나 시퀀스가 비어있으면 타이머 작동 안 함
        if (!useSequence || sequenceList.Count == 0) return;

        timer -= Time.deltaTime * timeScale;

        if (timer <= 0)
        {
            // 다음 신호 단계로 이동 (순환 구조)
            currentSequenceIndex = (currentSequenceIndex + 1) % sequenceList.Count;
            ApplyStateAndResetTimer(sequenceList[currentSequenceIndex].state);
        }
    }

    /// <summary>
    /// 새로운 상태를 가동하고 해당 시퀀스 인덱스의 duration에 맞게 타이머를 세팅합니다.
    /// </summary>
    private void ApplyStateAndResetTimer(LightState newState)
    {
        SetState(newState);
        if (sequenceList.Count > currentSequenceIndex)
        {
            timer = sequenceList[currentSequenceIndex].duration;
        }
    }

    /// <summary>
    /// 외부 컨트롤러(Intersection 등)가 이 신호등을 장악할 때 직접 제어하는 함수
    /// </summary>
    public void SetState(LightState newState)
    {
        CurrentState = newState;

        // 1. 등록된 모든 그룹의 오브젝트를 전부 끄기
        foreach (var group in lightGroups)
        {
            if (group.activeObjects != null)
            {
                foreach (var obj in group.activeObjects)
                {
                    if (obj != null) obj.SetActive(false);
                }
            }
        }

        // 2. 현재 새로 지정된 상태에 해당하는 오브젝트들만 켜기
        foreach (var group in lightGroups)
        {
            if (group.state == newState)
            {
                if (group.activeObjects != null)
                {
                    foreach (var obj in group.activeObjects)
                    {
                        if (obj != null) obj.SetActive(true);
                    }
                }
                break;
            }
        }
    }

    /// <summary>
    /// 외부 컨트롤러가 이 신호등을 조율하기 위해 자체 시퀀스 루프를 잠재우는 인터페이스
    /// </summary>
    public void SetControlledByExternal(bool isControlled)
    {
        useSequence = !isControlled;
    }
}
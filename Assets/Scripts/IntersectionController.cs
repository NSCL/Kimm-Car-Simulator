using System.Collections.Generic;
using UnityEngine;
using static TrafficLight;

public class IntersectionController : MonoBehaviour
{
    [System.Serializable]
    public struct IntersectionPhase
    {
        [Tooltip("이 페이즈의 이름 (구분용 예: 동서직진 남북정지)")]
        public string phaseName;

        [Tooltip("Group A(동-서) 신호등들의 상태")]
        public LightState groupAState;

        [Tooltip("Group B(남-북) 신호등들의 상태")]
        public LightState groupBState;

        [Tooltip("이 페이즈가 유지될 시간(초)")]
        public float duration;
    }

    [Header("신호등 그룹 구성")]
    [Tooltip("동서 방향 등 마주 보며 같이 움직이는 신호등 그룹을 넣어주세요.")]
    [SerializeField] private List<TrafficLight> groupALights = new List<TrafficLight>();

    [Tooltip("남북 방향 등 마주 보며 같이 움직이는 신호등 그룹을 넣어주세요.")]
    [SerializeField] private List<TrafficLight> groupBLights = new List<TrafficLight>();

    [Header("교차로 신호 스케줄 설정")]
    [SerializeField] private List<IntersectionPhase> phases = new List<IntersectionPhase>();

    [Header("통합 시뮬레이션 제어")]
    [Tooltip("교차로 전체 및 하위 신호등들의 시간 배율입니다.")]
    [Range(0.1f, 10f)]
    public float intersectionTimeScale = 1.0f;

    // 현재 제어 중인 상태 정보
    private int currentPhaseIndex = 0;
    private float phaseTimer = 0f;

    private void Start()
    {
        // 1. 가져온 모든 신호등의 제어권을 컨트롤러로 귀속시킵니다.
        InitializeTrafficLights();

        // 2. 스케줄에 첫 번째 페이즈가 설정되어 있다면 즉시 가동합니다.
        if (phases.Count > 0)
        {
            currentPhaseIndex = 0;
            ApplyPhase(phases[currentPhaseIndex]);
        }
    }

    private void Update()
    {
        if (phases.Count == 0) return;

        // 3. 실시간으로 변하는 인스펙터의 TimeScale을 모든 하위 신호등에 실시간 동기화시킵니다.
        SyncTimeScales();

        // 4. 타이머 감쇄 (컨트롤러의 시간 배율에 맞춤)
        phaseTimer -= Time.deltaTime * intersectionTimeScale;

        if (phaseTimer <= 0)
        {
            // 다음 페이즈로 이동 (끝나면 다시 처음으로)
            currentPhaseIndex = (currentPhaseIndex + 1) % phases.Count;
            ApplyPhase(phases[currentPhaseIndex]);
        }
    }

    /// <summary>
    /// 등록된 모든 신호등의 독립 주행 루틴을 잠재우고 통제권을 빼앗습니다.
    /// </summary>
    private void InitializeTrafficLights()
    {
        foreach (var light in groupALights)
        {
            if (light != null)
            {
                light.SetControlledByExternal(true);
            }
        }
        foreach (var light in groupBLights)
        {
            if (light != null)
            {
                light.SetControlledByExternal(true);
            }
        }
    }

    /// <summary>
    /// 하위 신호등들에게 실시간으로 마스터 타임스케일을 동기화해 줍니다.
    /// </summary>
    private void SyncTimeScales()
    {
        foreach (var light in groupALights)
        {
            if (light != null) light.timeScale = intersectionTimeScale;
        }
        foreach (var light in groupBLights)
        {
            if (light != null) light.timeScale = intersectionTimeScale;
        }
    }

    /// <summary>
    /// 특정 페이즈 명령을 그룹별 신호등들에 하달하고 타이머를 세팅합니다.
    /// </summary>
    private void ApplyPhase(IntersectionPhase targetPhase)
    {
        // Group A에 명령 전달
        foreach (var light in groupALights)
        {
            if (light != null) light.SetState(targetPhase.groupAState);
        }

        // Group B에 명령 전달
        foreach (var light in groupBLights)
        {
            if (light != null) light.SetState(targetPhase.groupBState);
        }

        // 해당 페이즈 타이머 설정
        phaseTimer = targetPhase.duration;
    }
}
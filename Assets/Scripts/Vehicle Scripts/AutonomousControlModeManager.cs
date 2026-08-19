using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using TMPro;

/// <summary>
/// KIMM Car Simulator 전용 수동(Manual) / 자율주행(Auto) 제어 모드 스위처.
/// 'M' 키(또는 UI 클릭)로 Manual Mode ↔ Auto Mode 1:1 토글 스위칭을 수행하며,
/// Auto Mode 진입 시 키보드/게임패드 수동 입력을 100% 완전 차단하고 텔레메트리 패널 배경 색상을 파격 전환합니다.
/// </summary>
[DisallowMultipleComponent]
public class AutonomousControlModeManager : MonoBehaviour
{
    private static AutonomousControlModeManager _instance;
    public static AutonomousControlModeManager Instance => _instance;

    [Header("Current Mode Status")]
    [SerializeField] private bool isAutoMode = false;
    public bool IsAutoMode => isAutoMode;

    [Header("Telemetry Panel Visual Element")]
    public Image telemetryPanelBackground;    // 텔레메트리 패널 배경 이미지
    public TextMeshProUGUI modeStatusText;     // 모드 표시 텍스트 (선택사항)

    [Header("Spawn / Goal Button UI Elements")]
    public Image spawnButtonImage;            // Edit Mode 핀 버튼 이미지
    public Sprite manualSpawnSprite;           // Manual Mode 핀 아이콘 (spawn_2)
    public Sprite autoGoalSprite;              // Auto Mode 핀 아이콘 (spawn_icon - 'G' 깃발)

    [Header("Theme Colors")]
    public Color manualBgColor = new Color(0.08f, 0.08f, 0.1f, 0.9f);            // 차분한 딥 블랙 배경
    public Color autoBgColor = new Color(0.02f, 0.12f, 0.25f, 0.95f);           // 스릴 있는 사이버 딥 블루 배경

    private VehicleInputManager _inputManager;

    private void Awake()
    {
        _instance = this;
    }

    private void Start()
    {
        _inputManager = FindFirstObjectByType<VehicleInputManager>();
        ApplyModeVisualsAndControl();
    }

    private void Update()
    {
        // 🌟 'M' 키 스캔 (New Input System 100% 안전 스캔)
        var keyboard = Keyboard.current;
        if (keyboard != null && keyboard.mKey.wasPressedThisFrame)
        {
            ToggleAutoMode();
        }
    }

    /// <summary>
    /// Manual Mode ↔ Auto Mode 1:1 토글 스위칭
    /// </summary>
    public void ToggleAutoMode()
    {
        SetAutoMode(!isAutoMode);
    }

    /// <summary>
    /// 지정된 제어 모드로 전환
    /// </summary>
    public void SetAutoMode(bool enableAuto)
    {
        isAutoMode = enableAuto;
        ApplyModeVisualsAndControl();

        string modeName = isAutoMode ? "🤖 [AUTO MODE]" : "🎮 [MANUAL MODE]";
        Debug.Log($"🚀 [ControlModeManager] Switched to {modeName} | Keyboard Input Active: {!isAutoMode}");
    }

    private void ApplyModeVisualsAndControl()
    {
        if (_inputManager == null) _inputManager = FindFirstObjectByType<VehicleInputManager>();

        // 1. 키보드/게임패드 수동 입력 활성화/차단 100% 직통 제어!
        if (_inputManager != null)
        {
            _inputManager.SetInputActive(!isAutoMode);
        }

        // 2. 텔레메트리 패널 배경 visual 테마 색상 1:1 스위칭!
        if (telemetryPanelBackground != null)
        {
            telemetryPanelBackground.color = isAutoMode ? autoBgColor : manualBgColor;
        }

        if (modeStatusText != null)
        {
            modeStatusText.text = isAutoMode ? "AUTO" : "MANUAL";
            modeStatusText.color = isAutoMode ? autoBgColor : manualBgColor;
        }

        // 3. Edit Mode 핀 버튼 아이콘 전환 (Manual: spawn_2, Auto: spawn_icon 'G' 깃발)
        if (spawnButtonImage != null)
        {
            if (isAutoMode && autoGoalSprite != null)
            {
                spawnButtonImage.sprite = autoGoalSprite;
            }
            else if (!isAutoMode && manualSpawnSprite != null)
            {
                spawnButtonImage.sprite = manualSpawnSprite;
            }
        }
    }
}

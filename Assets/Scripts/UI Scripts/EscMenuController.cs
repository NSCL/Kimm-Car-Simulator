using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// .exe 배포 및 런타임 환경에서 ESC 키 입력 시 메인 메뉴/세팅 패널을 토글 팝업하고,
/// 일시정지(Pause), 차량 Config 선택, 단축키 매뉴얼, 차량 리셋, 프로그램 종료(Quit)를 제어하는 통합 컨트롤러.
/// </summary>
public class EscMenuController : MonoBehaviour
{
    public static EscMenuController Instance { get; private set; }

    [Header("UI Panels")]
    public GameObject escMenuPanel;          // ESC 눌렀을 때 뜰 메인 일시정지 메뉴 패널
    public GameObject controlsManualPanel;   // 단축키 매뉴얼 / 도움말 팝업 패널

    [Header("State")]
    public bool isMenuOpen = false;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        // 씬 시작 시 메뉴/도움말 패널 비활성화
        if (escMenuPanel != null) escMenuPanel.SetActive(false);
        if (controlsManualPanel != null) controlsManualPanel.SetActive(false);
    }

    private void Update()
    {
        // Unity New Input System 전용 키 입력 감지
        if (Keyboard.current != null && Keyboard.current.escapeKey.wasPressedThisFrame)
        {
            ToggleEscMenu();
        }
    }

    /// <summary>
    /// ESC 키 또는 ⚙️ Setup 버튼 누를 때 메뉴 토글
    /// </summary>
    public void ToggleEscMenu()
    {
        isMenuOpen = !isMenuOpen;

        if (escMenuPanel != null)
        {
            escMenuPanel.SetActive(isMenuOpen);
        }

        // 세부 도움말 패널이 열려있었다면 닫기
        if (!isMenuOpen)
        {
            if (controlsManualPanel != null) controlsManualPanel.SetActive(false);
        }

        // 메뉴가 열리면 시뮬레이션 일시정지(TimeScale = 0), 닫히면 재개(TimeScale = 1)
        Time.timeScale = isMenuOpen ? 0f : 1f;

        // 마우스 커서 잠금 해제/보이기 제어
        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = true;
    }

    // =========================================================
    // UI 버튼 이벤트에 연결할 Public Methods
    // =========================================================

    /// <summary>
    /// [▶ Resume / 계속하기] 버튼 클릭 시
    /// </summary>
    public void OnClickResume()
    {
        if (isMenuOpen)
        {
            ToggleEscMenu();
        }
    }

    /// <summary>
    /// [🚗 Vehicle Parameters / Config 선택] 버튼 클릭 시
    /// 사용자가 파일 탐색기에서 [열기]를 딱 누르는 순간 FMU 파라미터 주입과 함께 ESC 메뉴가 자동으로 닫히고 주행 복귀!
    /// </summary>
    public void OnClickSelectVehicleConfig()
    {
        if (VehicleConfigManager.Instance != null)
        {
            // 윈도우 파일 탐색기를 열어 Config 선택 및 FMU 파라미터 자동 적용
            string selectedPath = VehicleConfigManager.Instance.OpenFileDialogAndSelectConfig();

            // 사용자가 취소하지 않고 파일을 정상적으로 [열기] 선택했다면 ESC 메뉴를 자동으로 닫고 주행 재개!
            if (!string.IsNullOrEmpty(selectedPath))
            {
                OnClickResume();
            }
        }
        else
        {
            Debug.LogWarning("[EscMenuController] 씬에 VehicleConfigManager가 존재하지 않습니다.");
        }
    }

    /// <summary>
    /// [⌨️ Controls Manual / 단축키 매뉴얼] 팝업 열기 버튼 클릭 시
    /// </summary>
    public void OnClickOpenControlsManual()
    {
        if (controlsManualPanel != null)
        {
            controlsManualPanel.SetActive(true);
        }
        else
        {
            Debug.LogWarning("[EscMenuController] controlsManualPanel이 할당되지 않았습니다.");
        }
    }

    /// <summary>
    /// [⌨️ Controls Manual / 단축키 매뉴얼] 팝업 닫기 버튼 클릭 시
    /// </summary>
    public void OnClickCloseControlsManual()
    {
        if (controlsManualPanel != null)
        {
            controlsManualPanel.SetActive(false);
        }
    }

    /// <summary>
    /// [↺ Reset Vehicle Position] 차량 위치 및 FMU 초기화 버튼 클릭 시
    /// </summary>
    public void OnClickResetVehiclePosition()
    {
        VehicleController vehicle = FindFirstObjectByType<VehicleController>();
        if (vehicle != null)
        {
            if (vehicle.spawnPoint != null)
            {
                vehicle.ResetVehicle(vehicle.spawnPoint.position, vehicle.spawnPoint.rotation);
            }
            else
            {
                vehicle.ResetVehicle(Vector3.zero, Quaternion.identity);
            }
            Debug.Log("[EscMenuController] 차량 위치 및 FMU 리셋 완료!");
        }

        // 리셋 후 메뉴 닫기
        OnClickResume();
    }

    /// <summary>
    /// [❌ Quit / 프로그램 종료] 버튼 클릭 시 (.exe 전용)
    /// </summary>
    public void OnClickQuitGame()
    {
        Debug.Log("[EscMenuController] 시뮬레이터 프로그램 종료.");
        Application.Quit();

#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#endif
    }
}

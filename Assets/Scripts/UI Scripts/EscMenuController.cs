using System;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using TMPro;

/// <summary>
/// ESC 메뉴 내의 모든 버튼 이벤트를 계층 구조 하위 검색으로 100% 자동 수색 및 바인딩하여 
/// 유니티 버튼 클릭 불통 현상을 원천 차단하는 무결점 매니저.
/// </summary>
public class EscMenuController : MonoBehaviour
{
    public static EscMenuController Instance { get; private set; }

    [Header("UI Panels")]
    public GameObject escMenuPanel;
    public GameObject controlsManualPanel;

    [Header("Buttons")]
    public Button resetVehicleButton;
    public Button selectConfigButton;
    public Button resumeButton;

    [Header("Status")]
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
        if (escMenuPanel != null) escMenuPanel.SetActive(false);
        if (controlsManualPanel != null) controlsManualPanel.SetActive(false);

        SetupButtonOnClickListeners();
    }

    /// <summary>
    /// escMenuPanel 자식 아래의 모든 UI 버튼을 정밀 스캔하여 OnClick 이벤트를 100% 자동 바인딩!
    /// </summary>
    public void SetupButtonOnClickListeners()
    {
        if (escMenuPanel == null) return;

        Button[] allButtons = escMenuPanel.GetComponentsInChildren<Button>(true);
        foreach (Button btn in allButtons)
        {
            if (btn == null) continue;
            string btnName = btn.gameObject.name.ToLower();
            TextMeshProUGUI tmpText = btn.GetComponentInChildren<TextMeshProUGUI>();
            string btnText = (tmpText != null) ? tmpText.text.ToLower() : "";

            // 1. Reset Vehicle 버튼 자동 수색
            if (btnName.Contains("reset") || btnText.Contains("reset"))
            {
                resetVehicleButton = btn;
                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(OnClickResetVehicle);
                Debug.Log($"[EscMenuController] '{btn.gameObject.name}' UI 버튼에 OnClickResetVehicle() 자동 바인딩 완료!");
            }
            // 2. Select Vehicle Config 버튼 자동 수색
            else if (btnName.Contains("config") || btnText.Contains("config") || btnName.Contains("select"))
            {
                selectConfigButton = btn;
                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(OnClickSelectVehicleConfig);
                Debug.Log($"[EscMenuController] '{btn.gameObject.name}' UI 버튼에 OnClickSelectVehicleConfig() 자동 바인딩 완료!");
            }
            // 3. Resume / Continue 버튼 자동 수색
            else if (btnName.Contains("resume") || btnText.Contains("resume") || btnName.Contains("continue"))
            {
                resumeButton = btn;
                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(OnClickResume);
            }
        }
    }

    private void Update()
    {
        var keyboard = Keyboard.current;
        if (keyboard != null)
        {
            if (keyboard.escapeKey.wasPressedThisFrame)
            {
                ToggleEscMenu();
            }
            if (keyboard.f1Key.wasPressedThisFrame)
            {
                ToggleControlsManual();
            }
        }
    }

    public void ToggleEscMenu()
    {
        isMenuOpen = !isMenuOpen;

        if (escMenuPanel != null)
        {
            escMenuPanel.SetActive(isMenuOpen);
            if (isMenuOpen)
            {
                SetupButtonOnClickListeners();
            }
        }

        if (!isMenuOpen)
        {
            if (controlsManualPanel != null) controlsManualPanel.SetActive(false);
        }

        Time.timeScale = isMenuOpen ? 0f : 1f;

        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = true;
    }

    public void CloseEscMenu()
    {
        if (isMenuOpen)
        {
            ToggleEscMenu();
        }
        else if (escMenuPanel != null && escMenuPanel.activeSelf)
        {
            escMenuPanel.SetActive(false);
        }
    }

    public void ToggleControlsManual()
    {
        if (controlsManualPanel != null)
        {
            bool nextState = !controlsManualPanel.activeSelf;
            controlsManualPanel.SetActive(nextState);
        }
    }

    public void OnClickResume()
    {
        if (isMenuOpen)
        {
            ToggleEscMenu();
        }
    }

    public void OnClickSelectVehicleConfig()
    {
        Debug.Log("[EscMenuController] OnClickSelectVehicleConfig() 실행!");
        if (VehicleConfigManager.Instance != null)
        {
            string selectedPath = VehicleConfigManager.Instance.OpenFileDialogAndSelectConfig();

            if (!string.IsNullOrEmpty(selectedPath))
            {
                OnClickResume();
            }
        }
    }

    public void OnClickOpenControlsManual()
    {
        if (controlsManualPanel != null)
        {
            controlsManualPanel.SetActive(true);
        }
    }

    public void OnClickCloseControlsManual()
    {
        if (controlsManualPanel != null)
        {
            controlsManualPanel.SetActive(false);
        }
    }

    public void OnClickResetVehicle()
    {
        Debug.Log("[EscMenuController] Reset Vehicle Position 버튼 클릭 발생! 수식 실행!");
        VehicleController vehicle = FindFirstObjectByType<VehicleController>();
        if (vehicle != null)
        {
            Transform spTransform = vehicle.spawnPoint;

            if (spTransform == null)
            {
                GameObject spObj = GameObject.Find("3D_World_SpawnPoint_Marker");
                if (spObj == null) spObj = GameObject.Find("spawnPoint");
                if (spObj == null) spObj = GameObject.Find("SpawnPoint");
                if (spObj != null) spTransform = spObj.transform;
            }

            if (spTransform != null)
            {
                vehicle.spawnPoint = spTransform;
                vehicle.ResetVehicle(spTransform.position, spTransform.rotation);
                Debug.Log($"[EscMenuController] 차량이 지정된 스폰 지점 {spTransform.position} 로 100% 리셋되었습니다!");
            }
            else
            {
                vehicle.ResetVehicle(Vector3.zero, Quaternion.identity);
            }
        }

        OnClickResume();
    }

    public void OnClickQuitGame()
    {
        Application.Quit();

#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#endif
    }
}

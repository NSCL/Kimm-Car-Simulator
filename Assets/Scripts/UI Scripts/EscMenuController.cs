using System;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using TMPro;

/// <summary>
/// ESC 메뉴 내의 UI 버튼 이벤트 연결 및 차량 리셋/Config 선택을 제어하는 컨트롤러.
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

            if (btnName.Contains("reset") || btnText.Contains("reset"))
            {
                resetVehicleButton = btn;
                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(OnClickResetVehicle);
            }
            else if (btnName.Contains("config") || btnText.Contains("config") || btnName.Contains("select"))
            {
                selectConfigButton = btn;
                btn.onClick.RemoveAllListeners();
                btn.onClick.AddListener(OnClickSelectVehicleConfig);
            }
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

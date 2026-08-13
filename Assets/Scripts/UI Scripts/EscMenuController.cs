using System;
using UnityEngine;
using UnityEngine.InputSystem;

/// <summary>
/// ESC 키 및 F1 키(매뉴얼 팝업 토글)와 UI 버튼 이벤트를 연결하고 시뮬레이션 일시정지/재개를 제어하는 컨트롤러.
/// </summary>
public class EscMenuController : MonoBehaviour
{
    public static EscMenuController Instance { get; private set; }

    [Header("UI Panels")]
    public GameObject escMenuPanel;
    public GameObject controlsManualPanel;

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
        }

        if (!isMenuOpen)
        {
            if (controlsManualPanel != null) controlsManualPanel.SetActive(false);
        }

        Time.timeScale = isMenuOpen ? 0f : 1f;

        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = true;
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
            if (vehicle.spawnPoint != null)
            {
                vehicle.ResetVehicle(vehicle.spawnPoint.position, vehicle.spawnPoint.rotation);
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

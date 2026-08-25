using UnityEngine;
using System.Collections;
using UnityEngine.InputSystem;

public class UIManager : MonoBehaviour
{
    public static UIManager Instance;

    [Header("Telemetry UI")]
    public GameObject telemetryPanelGroup;
    private bool isTelemetryOpen = false;

    [Header("UI Modules")]
    public ScreenEffectUI screenEffect;

    [Header("Input Actions")]
    public InputActionReference toggleTelemetryAction;

    private void OnEnable()
    {
        if(toggleTelemetryAction != null)
        {
            toggleTelemetryAction.action.Enable();
            toggleTelemetryAction.action.performed += OnToggleTelemetry;
        }
    }
    private void OnDisable()
    {
        if (toggleTelemetryAction != null)
        {
            toggleTelemetryAction.action.performed -= OnToggleTelemetry;
            toggleTelemetryAction.action.Disable();
        }
    }

    private void OnToggleTelemetry(InputAction.CallbackContext context)
    {
        ToggleTelemetryUI();
    }

    public void ToggleTelemetryUI()
    {
        isTelemetryOpen = !isTelemetryOpen;
        if(telemetryPanelGroup != null )
        {
            telemetryPanelGroup.SetActive(isTelemetryOpen);
        }
    }
    private void Awake()
    {
        if(Instance == null )
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Update()
    {
        
    }
    public void StartCollisionEffect()
    {
        if (screenEffect != null)
        {
            screenEffect.PlayFadeIn();
        }
    }
    public void EndCollisionEffect()
    {
        if (screenEffect != null)
        {
            screenEffect.TurnOffImmediately();
        }
    }
    //public IEnumerator EndCollisionEffect()
    //{
    //    if (screenEffect != null)
    //    {
    //        yield return screenEffect.PlayFadeOut();
    //    }
    //}
}

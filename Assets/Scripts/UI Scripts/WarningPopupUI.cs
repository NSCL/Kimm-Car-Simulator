using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 유효하지 않은 Vehicle Config JSON 파일 선택 시 
/// 사용자에게 누락된 필수 키 사유를 화면 중앙 팝업으로 명확히 안내하는 모달 UI 스크립트.
/// </summary>
public class WarningPopupUI : MonoBehaviour
{
    public static WarningPopupUI Instance { get; private set; }

    [Header("UI References")]
    public GameObject popupPanel;
    public TextMeshProUGUI titleText;
    public TextMeshProUGUI detailsText;
    public Button okButton;

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

        if (popupPanel != null)
        {
            popupPanel.SetActive(false);
        }

        if (okButton != null)
        {
            okButton.onClick.RemoveAllListeners();
            okButton.onClick.AddListener(HideWarning);
        }
    }

    private void Start()
    {
        if (VehicleConfigManager.Instance != null)
        {
            VehicleConfigManager.Instance.OnConfigValidationError += ShowWarning;
        }
    }

    private void OnDestroy()
    {
        if (VehicleConfigManager.Instance != null)
        {
            VehicleConfigManager.Instance.OnConfigValidationError -= ShowWarning;
        }
    }

    /// <summary>
    /// 양식 불일치 경고 팝업 표시
    /// </summary>
    public void ShowWarning(string title, List<string> details)
    {
        if (popupPanel == null)
        {
            CreateRuntimePopupUI(title, details);
            return;
        }

        popupPanel.SetActive(true);
        if (titleText != null) titleText.text = title;

        if (detailsText != null)
        {
            string content = "<b>[경고] 올바르지 않은 Vehicle Config 양식입니다!</b>\n\n";
            int maxShow = Mathf.Min(details.Count, 8);
            for (int i = 0; i < maxShow; i++)
            {
                content += $"• {details[i]}\n";
            }
            if (details.Count > 8)
            {
                content += $"...외 {details.Count - 8}개 오류 항목 추가 발견됨\n";
            }
            content += "\n<color=red>* 차량 파라미터 변경이 취소되었으며 기존 세팅이 유지됩니다.</color>";
            detailsText.text = content;
        }
    }

    public void HideWarning()
    {
        if (popupPanel != null)
        {
            popupPanel.SetActive(false);
        }
    }

    /// <summary>
    /// UI 씬에 팝업 오브젝트가 없는 경우 런타임 캔버스 팝업 자동 생성 헬퍼
    /// </summary>
    private void CreateRuntimePopupUI(string title, List<string> details)
    {
        Canvas canvas = FindFirstObjectByType<Canvas>();
        if (canvas == null) return;

        GameObject panelObj = new GameObject("WarningPopupPanel_Runtime");
        panelObj.transform.SetParent(canvas.transform, false);

        RectTransform rt = panelObj.AddComponent<RectTransform>();
        rt.anchorMin = new Vector2(0.2f, 0.25f);
        rt.anchorMax = new Vector2(0.8f, 0.75f);
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;

        Image img = panelObj.AddComponent<Image>();
        img.color = new Color(0.12f, 0.12f, 0.14f, 0.96f);

        GameObject textObj = new GameObject("DetailsText");
        textObj.transform.SetParent(panelObj.transform, false);
        RectTransform textRt = textObj.AddComponent<RectTransform>();
        textRt.anchorMin = new Vector2(0.05f, 0.2f);
        textRt.anchorMax = new Vector2(0.95f, 0.9f);
        textRt.offsetMin = Vector2.zero;
        textRt.offsetMax = Vector2.zero;

        TextMeshProUGUI tmp = textObj.AddComponent<TextMeshProUGUI>();
        tmp.fontSize = 16;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.TopLeft;

        string content = $"<b><size=20><color=yellow>{title}</color></size></b>\n\n";
        int maxShow = Mathf.Min(details.Count, 6);
        for (int i = 0; i < maxShow; i++)
        {
            content += $"• {details[i]}\n";
        }
        if (details.Count > 6)
        {
            content += $"...외 {details.Count - 6}개 오류 항목 발견됨\n";
        }
        content += "\n<color=#FF6B6B>* 올바르지 않은 양식이므로 적용이 거부되었습니다.</color>";
        tmp.text = content;

        GameObject btnObj = new GameObject("ConfirmButton");
        btnObj.transform.SetParent(panelObj.transform, false);
        RectTransform btnRt = btnObj.AddComponent<RectTransform>();
        btnRt.anchorMin = new Vector2(0.4f, 0.05f);
        btnRt.anchorMax = new Vector2(0.6f, 0.18f);
        btnRt.offsetMin = Vector2.zero;
        btnRt.offsetMax = Vector2.zero;

        Image btnImg = btnObj.AddComponent<Image>();
        btnImg.color = new Color(0.2f, 0.6f, 1.0f, 1.0f);

        Button btn = btnObj.AddComponent<Button>();
        btn.targetGraphic = btnImg;

        GameObject btnTextObj = new GameObject("BtnText");
        btnTextObj.transform.SetParent(btnObj.transform, false);
        RectTransform btnTextRt = btnTextObj.AddComponent<RectTransform>();
        btnTextRt.anchorMin = Vector2.zero;
        btnTextRt.anchorMax = Vector2.one;
        btnTextRt.offsetMin = Vector2.zero;
        btnTextRt.offsetMax = Vector2.zero;

        TextMeshProUGUI btnTmp = btnTextObj.AddComponent<TextMeshProUGUI>();
        btnTmp.text = "확인 (OK)";
        btnTmp.fontSize = 16;
        btnTmp.color = Color.white;
        btnTmp.alignment = TextAlignmentOptions.Center;

        btn.onClick.AddListener(() => {
            Destroy(panelObj);
        });

        popupPanel = panelObj;
    }
}

using System.Collections.Generic;
using UnityEngine;
using TMPro;

/// <summary>
/// MapChanger와 UI TextMeshPro Dropdown을 연결해주는 UI 바인딩 스크립트.
/// Proving Ground 등 긴 맵 이름도 줄바꿈 없이 폰트 크기가 100% 자동 축소(Auto-Sizing)되어 예쁘게 표시됩니다.
/// </summary>
public class MapChangerUI : MonoBehaviour
{
    [Header("UI Component Reference")]
    [Tooltip("맵 목록을 표시하고 선택할 TextMeshPro Dropdown 컴포넌트")]
    public TMP_Dropdown mapDropdown;

    private void Start()
    {
        if (mapDropdown == null)
        {
            mapDropdown = GetComponent<TMP_Dropdown>();
        }

        FixDropdownTextAutoSizing();

        if (mapDropdown != null)
        {
            PopulateDropdownOptions();
        }

        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted += OnMapChangeStarted;
            MapChanger.Instance.OnMapChangeCompleted += OnMapChangeCompleted;
        }
    }

    private void OnDestroy()
    {
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted -= OnMapChangeStarted;
            MapChanger.Instance.OnMapChangeCompleted -= OnMapChangeCompleted;
        }
    }

    /// <summary>
    /// 긴 맵 이름도 두 줄로 넘치거나 레이아웃이 깨지지 않도록 폰트 자동 축소(Auto-Sizing) 및 줄바꿈 차단 적용
    /// </summary>
    private void FixDropdownTextAutoSizing()
    {
        if (mapDropdown == null) return;

        if (mapDropdown.captionText != null)
        {
            mapDropdown.captionText.enableAutoSizing = true;
            mapDropdown.captionText.fontSizeMin = 8f;
            mapDropdown.captionText.fontSizeMax = 13f;
            mapDropdown.captionText.enableWordWrapping = false;
            mapDropdown.captionText.overflowMode = TextOverflowModes.Ellipsis;
        }

        if (mapDropdown.itemText != null)
        {
            mapDropdown.itemText.enableAutoSizing = true;
            mapDropdown.itemText.fontSizeMin = 8f;
            mapDropdown.itemText.fontSizeMax = 13f;
            mapDropdown.itemText.enableWordWrapping = false;
            mapDropdown.itemText.overflowMode = TextOverflowModes.Ellipsis;
        }
    }

    /// <summary>
    /// MapChanger의 mapList 데이터를 드롭다운 메뉴로 동적 등록
    /// </summary>
    public void PopulateDropdownOptions()
    {
        if (mapDropdown == null || MapChanger.Instance == null) return;

        mapDropdown.ClearOptions();
        List<TMP_Dropdown.OptionData> options = new List<TMP_Dropdown.OptionData>();

        foreach (var map in MapChanger.Instance.mapList)
        {
            TMP_Dropdown.OptionData option = new TMP_Dropdown.OptionData();
            option.text = map.mapName;
            option.image = map.mapThumbnail;
            options.Add(option);
        }

        mapDropdown.AddOptions(options);

        mapDropdown.SetValueWithoutNotify(MapChanger.Instance.currentMapIndex);
        mapDropdown.RefreshShownValue();

        FixDropdownTextAutoSizing();
    }

    private void OnMapChangeStarted()
    {
        if (mapDropdown != null)
        {
            mapDropdown.interactable = false;
        }
    }

    private void OnMapChangeCompleted()
    {
        if (mapDropdown != null)
        {
            mapDropdown.interactable = true;
            mapDropdown.SetValueWithoutNotify(MapChanger.Instance.currentMapIndex);
            mapDropdown.RefreshShownValue();
            FixDropdownTextAutoSizing();
        }
    }
}

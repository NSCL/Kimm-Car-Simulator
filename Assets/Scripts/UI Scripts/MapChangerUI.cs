using System.Collections.Generic;
using UnityEngine;
using TMPro;

/// <summary>
/// MapChanger와 UI TextMeshPro Dropdown을 연결해주는 UI 연동 스크립트
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

        if (mapDropdown != null)
        {
            PopulateDropdownOptions();
            mapDropdown.onValueChanged.AddListener(OnDropdownValueChanged);
        }

        // MapChanger 이벤트 구독
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted.AddListener(OnMapChangeStarted);
            MapChanger.Instance.OnMapChangeCompleted.AddListener(OnMapChangeCompleted);
        }
    }

    private void OnDestroy()
    {
        if (mapDropdown != null)
        {
            mapDropdown.onValueChanged.RemoveListener(OnDropdownValueChanged);
        }

        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.OnMapChangeStarted.RemoveListener(OnMapChangeStarted);
            MapChanger.Instance.OnMapChangeCompleted.RemoveListener(OnMapChangeCompleted);
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

        // 현재 맵 인덱스로 선택 상태 맞춤
        mapDropdown.SetValueWithoutNotify(MapChanger.Instance.currentMapIndex);
        mapDropdown.RefreshShownValue();
    }

    private void OnDropdownValueChanged(int index)
    {
        if (MapChanger.Instance != null)
        {
            MapChanger.Instance.ChangeMap(index);
        }
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
        }
    }
}

using UnityEngine;
using UnityEditor;
using System.Collections.Generic;

[CustomPropertyDrawer(typeof(FMUVariableAttribute))]
public class FMUVariableDrawer : PropertyDrawer
{
    public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
    {
        // 씬에서 FMUManager 찾기
        FMUManager manager = Object.FindAnyObjectByType<FMUManager>();

        if (manager == null || manager.variables == null || manager.variables.Count == 0)
        {
            // 매니저가 없거나 변수가 없으면 그냥 텍스트 박스로 그림
            EditorGUI.PropertyField(position, property, label);
            return;
        }

        FMUVariableAttribute attr = (FMUVariableAttribute)attribute;
        List<string> options = new List<string> { "None" };

        foreach (var v in manager.variables)
        {
            // 필터링: OnlyInput이 true면 causality가 input인 것만 추가
            if (attr.OnlyInput)
            {
                if (v.causality == "input") options.Add(v.name);
            }
            else
            {
                options.Add(v.name);
            }
        }

        // 현재 선택된 값 찾기
        int index = options.IndexOf(property.stringValue);
        if (index == -1) index = 0;

        // 드롭다운 그리기
        int newIndex = EditorGUI.Popup(position, label.text, index, options.ToArray());

        // 값 저장
        if (newIndex >= 0 && newIndex < options.Count)
        {
            string selected = options[newIndex];
            property.stringValue = (selected == "None") ? "" : selected;
        }
    }
}
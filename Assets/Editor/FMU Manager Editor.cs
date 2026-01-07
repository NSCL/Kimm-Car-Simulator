using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.IO;
// using FMI; // 필요시 주석 해제

[CustomEditor(typeof(FMUManager))]
public class FMUManagerEditor : Editor
{
    // 토글 상태를 기억하기 위한 변수 (true면 펼침, false면 접음)
    private bool _showInputs = true;
    private bool _showOutputs = false; // Output은 보통 많으니 기본적으로 접어둠

    public override void OnInspectorGUI()
    {
        FMUManager script = (FMUManager)target;

        GUIStyle boldStyle = new GUIStyle(EditorStyles.boldLabel);

        // =========================================================
        // 1. FMU 선택
        // =========================================================
        GUILayout.Label("FMU Configuration", boldStyle);

        string[] options = GetFMUListFromResources();

        int curIdx = System.Array.IndexOf(options, script.selectedFMUName);
        if (curIdx == -1) curIdx = 0;

        int newIdx = EditorGUILayout.Popup("Select FMU", curIdx, options);

        if (newIdx != curIdx)
        {
            Undo.RecordObject(script, "Select FMU");
            script.selectedFMUName = (newIdx == 0) ? "" : options[newIdx];
            LoadVariablesFromAsset(script);
            EditorUtility.SetDirty(script);
        }

        GUILayout.Space(10);

        // =========================================================
        // 2. 변수 목록 (폴드아웃 적용)
        // =========================================================
        if (script.variables.Count > 0)
        {
            // --- [Input 변수들] ---
            // 먼저 Input 변수만 따로 리스트를 뽑아봅니다 (개수 세기용)
            var inputVars = script.variables.FindAll(v => v.causality == "input");

            // 폴드아웃 제목 그리기 (예: "Inputs (Write) [5]")
            _showInputs = EditorGUILayout.Foldout(_showInputs, $"Inputs (Write) [{inputVars.Count}]", true);

            if (_showInputs) // 펼쳐져 있을 때만 그리기
            {
                EditorGUI.indentLevel++; // 들여쓰기해서 계층 구조 표현
                foreach (var v in script.variables)
                {
                    if (v.causality == "input")
                    {
                        // 변수 이름이 너무 길면 잘릴 수 있으니 툴팁 추가 등 가능
                        v.value = EditorGUILayout.DoubleField(v.name, v.value);
                    }
                }
                EditorGUI.indentLevel--; // 들여쓰기 원상복구
            }

            GUILayout.Space(5);

            // --- [Output 변수들] ---
            var outputVars = script.variables.FindAll(v => v.causality == "output");

            // Output은 보통 많으니까 기본적으로 접어두게 설정했습니다 (_showOutputs 초기값 false)
            _showOutputs = EditorGUILayout.Foldout(_showOutputs, $"Outputs (Read Only) [{outputVars.Count}]", true);

            if (_showOutputs)
            {
                EditorGUI.indentLevel++;
                GUI.enabled = false; // 읽기 전용 모드 시작

                foreach (var v in script.variables)
                {
                    if (v.causality == "output")
                    {
                        EditorGUILayout.DoubleField(v.name, v.value);
                    }
                }

                GUI.enabled = true; // 읽기 전용 모드 끝
                EditorGUI.indentLevel--;
            }
        }
        else if (!string.IsNullOrEmpty(script.selectedFMUName))
        {
            EditorGUILayout.HelpBox("변수 리스트가 비어있습니다.", MessageType.Warning);
            if (GUILayout.Button("Reload Variables")) LoadVariablesFromAsset(script);
        }

        GUILayout.Space(20);

        // =========================================================
        // 3. 나머지 기본 변수들
        // =========================================================
        DrawDefaultInspector();
    }

    void LoadVariablesFromAsset(FMUManager script)
    {
        script.variables.Clear();
        if (string.IsNullOrEmpty(script.selectedFMUName) || script.selectedFMUName == "None") return;

        // ModelDescription 찾기
        ModelDescription fmuData = Resources.Load<ModelDescription>(script.selectedFMUName);

        if (fmuData != null)
        {
            foreach (var scalarVar in fmuData.modelVariables)
            {
                RuntimeFMUVariable newVar = new RuntimeFMUVariable();
                newVar.name = scalarVar.name;
                newVar.causality = scalarVar.causality;
                newVar.value = 0f;
                script.variables.Add(newVar);
            }
        }
    }

    string[] GetFMUListFromResources()
    {
        List<string> names = new List<string> { "None" };
        string resPath = Application.dataPath + "/Resources";

        if (Directory.Exists(resPath))
        {
            string[] files = Directory.GetFiles(resPath, "*.asset");
            foreach (string file in files)
            {
                names.Add(Path.GetFileNameWithoutExtension(file));
            }
        }
        return names.ToArray();
    }
}
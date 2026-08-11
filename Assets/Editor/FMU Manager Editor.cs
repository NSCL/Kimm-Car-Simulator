using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.IO;
using System.Globalization;

/// <summary>
/// FMUManager의 유니티 커스텀 인스펙터 에디터 클래스.
/// ModelDescription 에셋으로부터 FMU 변수 및 파라미터(Inputs, Outputs, Parameters) 목록을 로드하고,
/// FMU 초기값(start value)을 올바르게 파싱하여 인스펙터 상에서 직관적으로 확인 및 조작할 수 있도록 지원합니다.
/// </summary>
[CustomEditor(typeof(FMUManager))]
public class FMUManagerEditor : Editor
{
    // 인스펙터 폴드아웃(Foldout) 섹션 표시 여부 제어 플래그
    private bool _showInputs = true;
    private bool _showParameters = true; // 차량 질량, 축거 등 파라미터(Parameter) 표시용
    private bool _showOutputs = false;   // Output은 기본적으로 접어둠

    public override void OnInspectorGUI()
    {
        FMUManager script = (FMUManager)target;

        GUIStyle boldStyle = new GUIStyle(EditorStyles.boldLabel);

        // =========================================================
        // 1. FMU 선택 드롭다운 (Resources 내 ModelDescription 에셋 검색)
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
        // 2. FMU 변수 및 파라미터 목록 표시 (Input / Parameter / Output)
        // =========================================================
        if (script.variables.Count > 0)
        {
            // --- [1] Input 변수 섹션 (제어 입력: Steer, Throttle, Brake 등) ---
            var inputVars = script.variables.FindAll(v => v.causality == "input");
            _showInputs = EditorGUILayout.Foldout(_showInputs, $"Inputs (Write) [{inputVars.Count}]", true);

            if (_showInputs)
            {
                EditorGUI.indentLevel++;
                foreach (var v in script.variables)
                {
                    if (v.causality == "input")
                    {
                        v.value = EditorGUILayout.DoubleField(v.name, v.value);
                    }
                }
                EditorGUI.indentLevel--;
            }

            GUILayout.Space(5);

            // --- [2] Parameter 변수 섹션 (차량 제원: 질량, 축거, 윤거, 관성모멘트 등) ---
            var paramVars = script.variables.FindAll(v => v.causality == "parameter");
            _showParameters = EditorGUILayout.Foldout(_showParameters, $"Parameters (Tunable) [{paramVars.Count}]", true);

            if (_showParameters)
            {
                EditorGUI.indentLevel++;
                foreach (var v in script.variables)
                {
                    if (v.causality == "parameter")
                    {
                        v.value = EditorGUILayout.DoubleField(v.name, v.value);
                    }
                }
                EditorGUI.indentLevel--;
            }

            GUILayout.Space(5);

            // --- [3] Output 변수 섹션 (동역학 출력: body_x, body_y, wheel outputs 등) ---
            var outputVars = script.variables.FindAll(v => v.causality == "output");
            _showOutputs = EditorGUILayout.Foldout(_showOutputs, $"Outputs (Read Only) [{outputVars.Count}]", true);

            if (_showOutputs)
            {
                EditorGUI.indentLevel++;
                GUI.enabled = false; // 읽기 전용으로 비활성화

                foreach (var v in script.variables)
                {
                    if (v.causality == "output")
                    {
                        EditorGUILayout.DoubleField(v.name, v.value);
                    }
                }

                GUI.enabled = true; // 읽기 전용 해제
                EditorGUI.indentLevel--;
            }
        }
        else if (!string.IsNullOrEmpty(script.selectedFMUName))
        {
            EditorGUILayout.HelpBox("로드된 FMU 변수가 없습니다. 아래 버튼을 눌러 에셋 데이터를 새로고침하세요.", MessageType.Warning);
            if (GUILayout.Button("Reload Variables")) LoadVariablesFromAsset(script);
        }

        GUILayout.Space(20);

        // =========================================================
        // 3. 기본 인스펙터 요소 그려주기
        // =========================================================
        DrawDefaultInspector();
    }

    /// <summary>
    /// Resources 폴더 내 ScriptableObject(ModelDescription)로부터 FMU 변수 파라미터 수집.
    /// ModelDescription의 'start' 속성을 파싱하여 인스펙터 및 RuntimeFMUVariable.value 초기값으로 설정합니다.
    /// </summary>
    void LoadVariablesFromAsset(FMUManager script)
    {
        script.variables.Clear();
        if (string.IsNullOrEmpty(script.selectedFMUName) || script.selectedFMUName == "None") return;

        // Resources 폴더에서 에셋 로드
        ModelDescription fmuData = Resources.Load<ModelDescription>(script.selectedFMUName);

        if (fmuData != null)
        {
            foreach (var scalarVar in fmuData.modelVariables)
            {
                RuntimeFMUVariable newVar = new RuntimeFMUVariable();
                newVar.name = scalarVar.name;
                newVar.causality = scalarVar.causality;

                // [핵심 로직] scalarVar.start 문자열을 double 실수 값으로 안전하게 파싱.
                // InvariantCulture를 사용하여 소수점(.) 형태의 문자열을 포맷 이슈 없이 일관성 있게 파싱합니다.
                if (!string.IsNullOrEmpty(scalarVar.start) &&
                    double.TryParse(scalarVar.start, NumberStyles.Any, CultureInfo.InvariantCulture, out double parsedValue))
                {
                    newVar.value = parsedValue;
                }
                else
                {
                    newVar.value = 0.0;
                }

                script.variables.Add(newVar);
            }
        }
    }

    /// <summary>
    /// Resources 폴더 내에 존재하는 모든 ModelDescription 에셋 파일 이름 수집
    /// </summary>
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
using UnityEngine;
using UnityEditor;
using System.IO;
using System.Collections.Generic;

[CustomEditor(typeof(FMUManager))]
public class FMUManagerEditor : Editor
{
    public override void OnInspectorGUI()
    {
        // 1. 타겟 스크립트 가져오기
        FMUManager script = (FMUManager)target;

        

        GUILayout.Space(10);
        GUILayout.Label("FMU Selection", EditorStyles.boldLabel);

        // 3. StreamingAssets 경로 확인
        string path = Application.streamingAssetsPath;
        if (!Directory.Exists(path))
        {
            EditorGUILayout.HelpBox("StreamingAssets 폴더를 찾을 수 없습니다.", MessageType.Warning);
            return;
        }

        // 4. 폴더 목록 스캔 (폴더 이름만 추출)
        string[] directories = Directory.GetDirectories(path);
        List<string> options = new List<string>();

        options.Add("None"); // 선택 안 함 옵션

        foreach (string dirPath in directories)
        {
            // 전체 경로에서 '폴더 이름'만 떼어내기
            string folderName = new DirectoryInfo(dirPath).Name;
            options.Add(folderName);
        }

        // 5. 현재 선택된 값이 목록의 몇 번째인지 찾기
        int currentIndex = options.IndexOf(script.selectedFMUName);
        if (currentIndex == -1) currentIndex = 0; // 목록에 없으면 None으로

        // 6. 드롭다운(Popup) 그리기
        int newIndex = EditorGUILayout.Popup("Target FMU", currentIndex, options.ToArray());

        // 7. 값이 바뀌었으면 저장
        if (newIndex != currentIndex)
        {
            // 실행 취소(Ctrl+Z) 가능하게 기록
            Undo.RecordObject(script, "Select FMU");

            if (newIndex == 0)
                script.selectedFMUName = ""; // None
            else
                script.selectedFMUName = options[newIndex];

            // 변경사항 저장 (이거 안 하면 씬 이동시 값 날아감)
            EditorUtility.SetDirty(script);
        }

        // (선택사항) 현재 선택된 값 텍스트로 보여주기
        if (!string.IsNullOrEmpty(script.selectedFMUName))
        {
            EditorGUILayout.HelpBox($"Selected: {script.selectedFMUName}", MessageType.Info);
        }

        // 2. [기본 변수 그리기] 
        // 이걸 호출해야 'simulationSpeed' 같은 다른 변수들이 화면에 나옵니다.
        DrawDefaultInspector();
    }
}
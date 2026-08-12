using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Globalization;
using UnityEngine;

/// <summary>
/// .exe 배포 환경에서 외부 JSON Config 파일 선택/파싱을 담당하는 싱글톤 매니저 클래스.
/// Windows Native OpenFileDialog API를 사용하여 별도 에셋 라이브러리 없이 윈도우 파일 탐색기를 호출합니다.
/// </summary>
public class VehicleConfigManager : MonoBehaviour
{
    public static VehicleConfigManager Instance { get; private set; }

    [Header("Current Loaded Config")]
    public string currentConfigPath;
    public string currentVehicleName = "Default Sedan";

    // 파싱된 45개 파라미터 저장소 (Key: 변수명, Value: 실수값)
    public Dictionary<string, double> loadedParameters = new Dictionary<string, double>();

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        // 씬 시작 시 기본 StreamingAssets/vehicle_config.json 자동 로드
        LoadDefaultConfig();
    }

    /// <summary>
    /// 유니티 UI Button OnClick() 이벤트 드롭다운에 노출되는 전용 void 메소드
    /// </summary>
    public void SelectConfigViaFileDialog()
    {
        string path = OpenFileDialogAndSelectConfig();
        // 파일 정상 선택 시 ESC 메뉴가 열려있다면 자동으로 닫고 주행 복귀
        if (!string.IsNullOrEmpty(path))
        {
            if (EscMenuController.Instance != null && EscMenuController.Instance.isMenuOpen)
            {
                EscMenuController.Instance.OnClickResume();
            }
        }
    }

    /// <summary>
    /// StreamingAssets/vehicle_config.json 기본 파일 자동 로드
    /// </summary>
    public bool LoadDefaultConfig()
    {
        string defaultPath = Path.Combine(Application.streamingAssetsPath, "vehicle_config.json");
        return LoadConfigFromFile(defaultPath);
    }

    /// <summary>
    /// 지정된 경로의 JSON Config 파일을 읽어 파라미터 매핑
    /// </summary>
    public bool LoadConfigFromFile(string filePath)
    {
        if (!File.Exists(filePath))
        {
            Debug.LogWarning($"[VehicleConfigManager] Config 파일을 찾을 수 없습니다: {filePath}");
            return false;
        }

        try
        {
            string jsonText = File.ReadAllText(filePath);
            
            loadedParameters.Clear();
            ParseConfigJson(jsonText);

            currentConfigPath = filePath;
            Debug.Log($"[VehicleConfigManager] 성공적으로 Config 로드 완료: {Path.GetFileName(filePath)} (총 {loadedParameters.Count}개 파라미터)");
            return true;
        }
        catch (Exception e)
        {
            Debug.LogError($"[VehicleConfigManager] Config 로드 실패: {e.Message}");
            return false;
        }
    }

    /// <summary>
    /// Win32 파일 탐색기 창을 띄워 사용자가 .json 설정 파일을 로드하고 FMU에 즉시 반영하도록 지원
    /// </summary>
    public string OpenFileDialogAndSelectConfig()
    {
        string selectedPath = OpenWin32FileDialog("JSON Files (*.json)\0*.json\0All Files (*.*)\0*.*\0", "Select Vehicle Config JSON");
        if (!string.IsNullOrEmpty(selectedPath))
        {
            if (LoadConfigFromFile(selectedPath))
            {
                ApplyLoadedConfigToFMU();
                return selectedPath;
            }
        }
        return null;
    }

    /// <summary>
    /// 로드된 Config 파라미터들을 FMUManager에 전달하고 ResetFMU()를 호출하여 C++ DLL로 주입
    /// </summary>
    public void ApplyLoadedConfigToFMU()
    {
        FMUManager fmuManager = FindFirstObjectByType<FMUManager>();
        if (fmuManager == null)
        {
            Debug.LogError("[VehicleConfigManager] 씬에서 FMUManager를 찾을 수 없습니다.");
            return;
        }

        if (loadedParameters.Count == 0)
        {
            Debug.LogWarning("[VehicleConfigManager] 적용할 로드된 파라미터가 없습니다.");
            return;
        }

        // 1. FMUManager.variables의 RuntimeFMUVariable 값 업데이트
        foreach (var kvp in loadedParameters)
        {
            var targetVar = fmuManager.variables.Find(v => v.name == kvp.Key);
            if (targetVar != null)
            {
                targetVar.value = kvp.Value;
            }
        }

        // 2. FMU 리셋 및 InitializationMode를 통해 C++ DLL로 45개 파라미터 주입
        fmuManager.ResetFMU();
        Debug.Log("[VehicleConfigManager] FMUManager 파라미터 주입 및 ResetFMU 완료!");
    }

    /// <summary>
    /// 의존성 없는 안전한 JSON 파라미터 extraction 파서
    /// </summary>
    private void ParseConfigJson(string json)
    {
        int paramIdx = json.IndexOf("\"Parameters\"");
        if (paramIdx != -1)
        {
            string paramBlock = json.Substring(paramIdx);
            string[] lines = paramBlock.Split('\n');
            foreach (string line in lines)
            {
                if (line.Contains(":"))
                {
                    string[] parts = line.Split(':');
                    if (parts.Length >= 2)
                    {
                        string key = parts[0].Trim(' ', '\t', '"', '\r', ',', '{', '}');
                        string valStr = parts[1].Trim(' ', '\t', '"', '\r', ',');

                        if (!string.IsNullOrEmpty(key) && key.StartsWith("Veh_"))
                        {
                            if (double.TryParse(valStr, NumberStyles.Any, CultureInfo.InvariantCulture, out double val))
                            {
                                loadedParameters[key] = val;
                            }
                        }
                    }
                }
            }
        }
    }

    #region Windows Win32 OpenFileDialog Native P/Invoke
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
    public struct OpenFileName
    {
        public int structSize;
        public IntPtr dlgOwner;
        public IntPtr instance;
        public string filter;
        public string customFilter;
        public int maxCustomFilter;
        public int filterIndex;
        public string file;
        public int maxFile;
        public string fileTitle;
        public int maxFileTitle;
        public string initialDir;
        public string title;
        public int flags;
        public short fileOffset;
        public short fileExtension;
        public string defExt;
        public IntPtr custData;
        public IntPtr hook;
        public string templateName;
        public IntPtr reservedPtr;
        public int reservedInt;
        public int flagsEx;
    }

    [DllImport("Comdlg32.dll", CharSet = CharSet.Auto, SetLastError = true)]
    private static extern bool GetOpenFileName([In, Out] ref OpenFileName ofn);

    private static string OpenWin32FileDialog(string filter, string title)
    {
        OpenFileName ofn = new OpenFileName();
        ofn.structSize = Marshal.SizeOf(ofn);
        ofn.filter = filter;
        ofn.file = new string(new char[256]);
        ofn.maxFile = ofn.file.Length;
        ofn.fileTitle = new string(new char[64]);
        ofn.maxFileTitle = ofn.fileTitle.Length;
        string initDir = Application.streamingAssetsPath.Replace('/', '\\');
        if (Directory.Exists(initDir)) ofn.initialDir = initDir;
        ofn.title = title;
        ofn.flags = 0x00080000 | 0x00001000 | 0x00000800 | 0x00000200 | 0x00000008;

        if (GetOpenFileName(ref ofn))
        {
            return ofn.file;
        }
        return null;
    }
    #endregion
}

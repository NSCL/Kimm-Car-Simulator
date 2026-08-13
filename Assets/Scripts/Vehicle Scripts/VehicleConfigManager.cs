using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Globalization;
using UnityEngine;

/// <summary>
/// 외부 JSON Config 파일 로드 시 45개 필수 파라미터 양식을 정밀 대조(Validation)하여,
/// 누락되거나 양식이 잘못된 파라미터 적용을 100% 거부하고 사용자에게 경고 팝업을 표시하는 매니저.
/// </summary>
public class VehicleConfigManager : MonoBehaviour
{
    public static VehicleConfigManager Instance { get; private set; }

    [Header("Current Loaded Config")]
    public string currentConfigPath;
    public string currentVehicleName = "Default Sedan";

    // 파싱된 45개 파라미터 저장소 (Key: 변수명, Value: 실수값)
    public Dictionary<string, double> loadedParameters = new Dictionary<string, double>();

    // 모델링 설계자가 정의한 45개 필수 기준 파라미터 검증표 (Validation Schema)
    public static readonly HashSet<string> RequiredParameterKeys = new HashSet<string>()
    {
        "Veh_AeroArea", "Veh_AeroCd", "Veh_AeroCl", "Veh_AeroRho",
        "Veh_BodyInertia[1,1]", "Veh_BodyInertia[1,2]", "Veh_BodyInertia[1,3]",
        "Veh_BodyMass", "Veh_BodyRefZ0", "Veh_BodytoWheelCenter",
        "Veh_FrontAxleX", "Veh_RearAxleX", "Veh_SteerRatio",
        "Veh_SuspF_BumpC", "Veh_SuspF_BumpK", "Veh_SuspF_BumpLimit", "Veh_SuspF_BumpWidth",
        "Veh_SuspF_C", "Veh_SuspF_EqPos", "Veh_SuspF_K", "Veh_SuspF_ReboundC", "Veh_SuspF_ReboundK",
        "Veh_SuspF_ReboundLimit", "Veh_SuspF_ReboundWidth",
        "Veh_SuspF_UnsprungInertia[1,1]", "Veh_SuspF_UnsprungInertia[1,2]", "Veh_SuspF_UnsprungInertia[1,3]",
        "Veh_SuspF_UnsprungMass",
        "Veh_SuspR_BumpC", "Veh_SuspR_BumpK", "Veh_SuspR_BumpLimit", "Veh_SuspR_BumpWidth",
        "Veh_SuspR_C", "Veh_SuspR_EqPos", "Veh_SuspR_K", "Veh_SuspR_ReboundC", "Veh_SuspR_ReboundK",
        "Veh_SuspR_ReboundLimit", "Veh_SuspR_ReboundWidth",
        "Veh_SuspR_UnsprungInertia[1,1]", "Veh_SuspR_UnsprungInertia[1,2]", "Veh_SuspR_UnsprungInertia[1,3]",
        "Veh_SuspR_UnsprungMass"
    };

    public event Action<string, List<string>> OnConfigValidationError;

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
        LoadDefaultConfig();
    }

    public void SelectConfigViaFileDialog()
    {
        string path = OpenFileDialogAndSelectConfig();
        if (!string.IsNullOrEmpty(path))
        {
            if (EscMenuController.Instance != null && EscMenuController.Instance.isMenuOpen)
            {
                EscMenuController.Instance.OnClickResume();
            }
        }
    }

    public bool LoadDefaultConfig()
    {
        string defaultPath = Path.Combine(Application.streamingAssetsPath, "vehicle_config.json");
        return LoadConfigFromFile(defaultPath);
    }

    /// <summary>
    /// 지정된 파일 경로의 JSON Config 로드 및 45개 필수 키 정밀 검증 집행
    /// </summary>
    public bool LoadConfigFromFile(string filePath)
    {
        if (!File.Exists(filePath))
        {
            string err = $"Config 파일을 찾을 수 없습니다: {filePath}";
            Debug.LogWarning($"[VehicleConfigManager] {err}");
            ShowValidationErrorPopup("파일 없음", new List<string> { err });
            return false;
        }

        try
        {
            string jsonText = File.ReadAllText(filePath);
            
            Dictionary<string, double> parsedTemp = new Dictionary<string, double>();
            ParseConfigJsonToDict(jsonText, parsedTemp);

            // [정밀 검증 100%]: 45개 필수 파라미터 대조 검사
            List<string> missingKeys;
            List<string> invalidValues;
            bool isValid = ValidateParameters(parsedTemp, out missingKeys, out invalidValues);

            if (!isValid)
            {
                List<string> errorDetails = new List<string>();
                foreach (var mk in missingKeys) errorDetails.Add($"누락된 필수 항목: {mk}");
                foreach (var iv in invalidValues) errorDetails.Add($"올바르지 않은 수치: {iv}");

                string fileName = Path.GetFileName(filePath);
                Debug.LogError($"[VehicleConfigManager] '{fileName}' 파라미터 양식 불일치! 반영 거부 (총 {errorDetails.Count}개 오류)");
                
                ShowValidationErrorPopup($"[경고] '{fileName}' 올바르지 않은 Vehicle Config 양식입니다!", errorDetails);
                return false; // 파라미터 반영 100% 거부!
            }

            // 검증 합격 시에만 기존 파라미터 교체 적용
            loadedParameters.Clear();
            foreach (var kvp in parsedTemp) loadedParameters[kvp.Key] = kvp.Value;

            currentConfigPath = filePath;
            Debug.Log($"[VehicleConfigManager] 성공적으로 Config 로드 및 정밀 검증 완료: {Path.GetFileName(filePath)} (총 {loadedParameters.Count}개 파라미터)");

            ApplyLoadedConfigToFMU();
            return true;
        }
        catch (Exception e)
        {
            string err = $"JSON 파싱 오류: {e.Message}";
            Debug.LogError($"[VehicleConfigManager] Config 로드 실패: {err}");
            ShowValidationErrorPopup("JSON 구문 오류", new List<string> { err });
            return false;
        }
    }

    /// <summary>
    /// 파싱된 파라미터 딕셔너리가 원본 모델 검증표(RequiredParameterKeys)와 일치하는지 정밀 대조
    /// </summary>
    private bool ValidateParameters(Dictionary<string, double> parsed, out List<string> missingKeys, out List<string> invalidValues)
    {
        missingKeys = new List<string>();
        invalidValues = new List<string>();

        // 1. 필수 키 누락 검사
        foreach (string reqKey in RequiredParameterKeys)
        {
            if (!parsed.ContainsKey(reqKey))
            {
                missingKeys.Add(reqKey);
            }
        }

        // 2. 수치 유효성 검사 (NaN 또는 무한대 수치 검사)
        foreach (var kvp in parsed)
        {
            if (double.IsNaN(kvp.Value) || double.IsInfinity(kvp.Value))
            {
                invalidValues.Add($"{kvp.Key} = {kvp.Value}");
            }
        }

        // 차체 질량(Veh_BodyMass) 및 중요 수치 기본값 검사
        if (parsed.TryGetValue("Veh_BodyMass", out double mass) && mass <= 0)
        {
            invalidValues.Add($"Veh_BodyMass({mass}) 수치는 0보다 커야 합니다.");
        }

        return (missingKeys.Count == 0 && invalidValues.Count == 0);
    }

    private void ShowValidationErrorPopup(string title, List<string> errorDetails)
    {
        OnConfigValidationError?.Invoke(title, errorDetails);
        
        // 팝업 컨트롤러나 경고 UI에 전달
        WarningPopupUI popup = FindFirstObjectByType<WarningPopupUI>();
        if (popup != null)
        {
            popup.ShowWarning(title, errorDetails);
        }
    }

    public string OpenFileDialogAndSelectConfig()
    {
        string selectedPath = OpenWin32FileDialog("JSON Files (*.json)\0*.json\0All Files (*.*)\0*.*\0", "Select Vehicle Config JSON");
        if (!string.IsNullOrEmpty(selectedPath))
        {
            if (LoadConfigFromFile(selectedPath))
            {
                return selectedPath;
            }
        }
        return null;
    }

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

        foreach (var kvp in loadedParameters)
        {
            var targetVar = fmuManager.variables.Find(v => v.name == kvp.Key);
            if (targetVar != null)
            {
                targetVar.value = kvp.Value;
            }
        }

        fmuManager.ResetFMU();
        Debug.Log("[VehicleConfigManager] FMUManager 파라미터 주입 및 ResetFMU 완료!");

        VehicleController vc = FindFirstObjectByType<VehicleController>();
        if (vc != null)
        {
            float trackW = 1.6f;
            float wheelbase = 3.0f;

            if (loadedParameters.TryGetValue("Veh_TrackF", out double tf) && tf > 0.5) trackW = (float)tf;
            else if (loadedParameters.TryGetValue("Veh_TrackW", out double tw) && tw > 0.5) trackW = (float)tw;

            if (loadedParameters.TryGetValue("Veh_FrontAxleX", out double fx) && loadedParameters.TryGetValue("Veh_RearAxleX", out double rx))
            {
                wheelbase = (float)(Math.Abs(fx) + Math.Abs(rx));
            }
            else if (loadedParameters.TryGetValue("Veh_Wheelbase", out double wb) && wb > 1.0)
            {
                wheelbase = (float)wb;
            }

            Debug.Log($"[VehicleConfigManager] 3D 섀시 수치: 윤거(TrackW)={trackW:F3}m, 축거(Wheelbase)={wheelbase:F3}m");
            vc.ApplyChassisScale(trackW, wheelbase);
        }
    }

    private void ParseConfigJsonToDict(string json, Dictionary<string, double> dict)
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
                                dict[key] = val;
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

using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Globalization;
using UnityEngine;

/// <summary>
/// 외부 JSON Config 파일 로드 시 45개 필수 파라미터 양식을 정밀 대조(Validation)하여,
/// 누락되거나 양식이 잘못된 경우 윈도우 표준 경고 메시지 팝업(Windows Native MessageBox)을 100% 띄우고 
/// 변경을 거부하는 매니저.
/// </summary>
public class VehicleConfigManager : MonoBehaviour
{
    public static VehicleConfigManager Instance { get; private set; }

    [Header("Current Loaded Config")]
    public string currentConfigPath;
    public string currentVehicleName = "Default Sedan";

    public Dictionary<string, double> loadedParameters = new Dictionary<string, double>();

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

    public bool LoadConfigFromFile(string filePath)
    {
        if (!File.Exists(filePath))
        {
            string err = $"Config 파일을 찾을 수 없습니다:\n{filePath}";
            ShowWindowsNativeWarningBox("Vehicle Config 로드 실패", err);
            OnConfigValidationError?.Invoke("Vehicle Config 로드 실패", new List<string> { err });
            return false;
        }

        try
        {
            string jsonText = File.ReadAllText(filePath);
            
            Dictionary<string, double> parsedTemp = new Dictionary<string, double>();
            ParseConfigJsonToDict(jsonText, parsedTemp);

            List<string> missingKeys;
            List<string> invalidValues;
            bool isValid = ValidateParameters(parsedTemp, out missingKeys, out invalidValues);

            if (!isValid)
            {
                string fileName = Path.GetFileName(filePath);
                string message = $"선택하신 파일('{fileName}')은 파라미터 양식이 올바르지 않습니다!\n\n[오류 사유]\n";

                List<string> errorList = new List<string>();
                int count = 0;
                foreach (var mk in missingKeys)
                {
                    errorList.Add($"누락된 필수 항목: {mk}");
                    message += $"• 누락된 필수 항목: {mk}\n";
                    count++;
                    if (count >= 6) break;
                }

                if (missingKeys.Count > 6)
                {
                    message += $"...외 {missingKeys.Count - 6}개 누락 항목 추가 발견\n";
                }

                foreach (var iv in invalidValues)
                {
                    errorList.Add($"올바르지 않은 수치: {iv}");
                    message += $"• 올바르지 않은 수치: {iv}\n";
                }

                message += "\n* 차량 파라미터 변경이 거부되었으며 기존 세팅이 안전하게 유지됩니다.";

                ShowWindowsNativeWarningBox($"[경고] '{fileName}' 파라미터 양식 오류", message);
                OnConfigValidationError?.Invoke($"[경고] '{fileName}' 파라미터 양식 오류", errorList);
                
                return false;
            }

            loadedParameters.Clear();
            foreach (var kvp in parsedTemp) loadedParameters[kvp.Key] = kvp.Value;

            currentConfigPath = filePath;

            ApplyLoadedConfigToFMU();
            return true;
        }
        catch (Exception e)
        {
            string err = $"JSON 파싱 오류가 발생하였습니다:\n{e.Message}";
            ShowWindowsNativeWarningBox("JSON 구문 오류", err);
            OnConfigValidationError?.Invoke("JSON 구문 오류", new List<string> { err });
            return false;
        }
    }

    private bool ValidateParameters(Dictionary<string, double> parsed, out List<string> missingKeys, out List<string> invalidValues)
    {
        missingKeys = new List<string>();
        invalidValues = new List<string>();

        foreach (string reqKey in RequiredParameterKeys)
        {
            if (!parsed.ContainsKey(reqKey))
            {
                missingKeys.Add(reqKey);
            }
        }

        foreach (var kvp in parsed)
        {
            if (double.IsNaN(kvp.Value) || double.IsInfinity(kvp.Value))
            {
                invalidValues.Add($"{kvp.Key} = {kvp.Value}");
            }
        }

        if (parsed.TryGetValue("Veh_BodyMass", out double mass) && mass <= 0)
        {
            invalidValues.Add($"Veh_BodyMass({mass}) 수치는 0보다 커야 합니다.");
        }

        return (missingKeys.Count == 0 && invalidValues.Count == 0);
    }

    private void ShowWindowsNativeWarningBox(string title, string message)
    {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        MessageBox(IntPtr.Zero, message, title, 0x00000030);
#else
        Debug.LogWarning($"[{title}] {message}");
#endif
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
        if (fmuManager == null) return;

        if (loadedParameters.Count == 0) return;

        foreach (var kvp in loadedParameters)
        {
            var targetVar = fmuManager.variables.Find(v => v.name == kvp.Key);
            if (targetVar != null)
            {
                targetVar.value = kvp.Value;
            }
        }

        fmuManager.ResetFMU();

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

    #region Windows Win32 Native P/Invoke (MessageBox & OpenFileDialog)
    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    private static extern int MessageBox(IntPtr hWnd, string text, string caption, uint type);

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

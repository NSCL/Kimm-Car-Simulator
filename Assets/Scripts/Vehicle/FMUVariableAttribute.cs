using UnityEngine;

// 이 파일은 Editor 폴더에 있으면 안 됩니다! 
// 일반 Scripts 폴더에 두세요.
public class FMUVariableAttribute : PropertyAttribute
{
    public bool OnlyInput;

    public FMUVariableAttribute(bool onlyInput = false)
    {
        this.OnlyInput = onlyInput;
    }
}
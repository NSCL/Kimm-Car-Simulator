using UnityEngine;
using System.Collections;

public class UIManager : MonoBehaviour
{
    public static UIManager Instance;
    [Header("UI Modules")]
    public ScreenEffectUI screenEffect;

    private void Awake()
    {
        if(Instance == null )
        {
            Instance = this;
        }
        else
        {
            Destroy(gameObject);
        }
    }
    public void StartCollisionEffect()
    {
        if (screenEffect != null)
        {
            screenEffect.PlayFadeIn();
        }
    }
    public void EndCollisionEffect()
    {
        if (screenEffect != null)
        {
            screenEffect.TurnOffImmediately();
        }
    }
    //public IEnumerator EndCollisionEffect()
    //{
    //    if (screenEffect != null)
    //    {
    //        yield return screenEffect.PlayFadeOut();
    //    }
    //}
}

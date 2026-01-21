using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ScreenEffectUI : MonoBehaviour
{
    private CanvasGroup canvasGroup;
    public float fadeSpeed = 2.0f;

    private void Awake()
    {
        canvasGroup = GetComponent<CanvasGroup>();
        if(canvasGroup==null) canvasGroup=gameObject.AddComponent<CanvasGroup>();
    }
    public void PlayFadeIn()
    {
        // 내(ScreenEffectUI)가 돌리고 있던 모든 코루틴(FadeOut 등)을 확실히 끔
        StopAllCoroutines();

        // 그리고 내 이름으로 새로 시작
        StartCoroutine(FadeInRoutine());
    }

    // 2. 페이드 아웃 시작 (매니저가 기다려야 하므로 Coroutine 객체 반환)
    //public Coroutine PlayFadeOut()
    //{
    //    StopAllCoroutines(); // FadeIn이 돌고 있었다면 즉살
    //    return StartCoroutine(FadeOutRoutine());
    //}

    public void TurnOffImmediately()
    {
        StopAllCoroutines(); // 혹시 돌고 있는 Fade In이 있다면 중지
        canvasGroup.alpha = 0.0f; // 즉시 투명하게
        canvasGroup.blocksRaycasts = false;
    }
    public IEnumerator FadeInRoutine()
    {
        canvasGroup.blocksRaycasts = true; // 클릭 방지

        while (canvasGroup.alpha < 1.0f)
        {
            // 알파값 증가 (점점 어두워짐)
            canvasGroup.alpha += Time.deltaTime*fadeSpeed;
            yield return null;
        }
        canvasGroup.alpha = 1.0f; // 확실하게 1로 마무리
    }

    //public IEnumerator FadeOutRoutine()
    //{
    //    while(canvasGroup.alpha>0.0f)
    //    {
    //        canvasGroup.alpha-= Time.deltaTime*fadeSpeed;
    //        yield return null;
    //    }
    //    canvasGroup.alpha=0.0f;
    //    canvasGroup.blocksRaycasts=false;
    //}
}

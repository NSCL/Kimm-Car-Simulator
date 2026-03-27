using UnityEngine;
using System.Collections.Generic;

public class PedestrianActor : MonoBehaviour
{
    [Header("Speed Settings")]
    public float walkSpeed = 1.5f;
    public float runSpeed = 4.0f;

    private List<WaypointData> path = new List<WaypointData>();
    private int currentIdx = 0;
    private bool isMoving = false;

    private Animator anim;
    // 마커 삭제용 명부
    public List<GameObject> myMarkers = new List<GameObject>();

    public void InitializePath(List<WaypointData> newPath, float customWalkSpeed, float customRunSpeed)
    {
        if (newPath == null || newPath.Count == 0) return;

        walkSpeed = customWalkSpeed;
        runSpeed = customRunSpeed;

        anim = GetComponentInChildren<Animator>();
        path = new List<WaypointData>(newPath);

        // 첫 번째 웨이포인트(0번)에서 스폰
        transform.position = path[0].position;
        transform.rotation = path[0].rotation;

        currentIdx = 1; // 다음 목표는 1번 점
        if (path.Count > 1) isMoving = true;
    }

    void Update()
    {
        if (!isMoving) return;

        WaypointData targetPoint = path[currentIdx];

        float currentSpeed = 0f;
        int animState = 0;
        if (targetPoint.state == ActorState.Walk) { currentSpeed = walkSpeed; animState = 1; }
        else if (targetPoint.state == ActorState.Run) { currentSpeed = runSpeed; animState = 2; }
        else if (targetPoint.state == ActorState.Idle) { currentSpeed = 0f; animState = 0; }
        if (anim != null) anim.SetInteger("State", animState);
        // 이동 및 회전 로직
        if (currentSpeed > 0f)
        {
            Vector3 direction = (targetPoint.position - transform.position).normalized;
            direction.y = 0;
            if (direction != Vector3.zero)
            {
                Quaternion lookRot = Quaternion.LookRotation(direction);
                transform.rotation = Quaternion.Slerp(transform.rotation, lookRot, Time.deltaTime * 10f);
            }
            transform.position = Vector3.MoveTowards(transform.position, targetPoint.position, currentSpeed * Time.deltaTime);
        }

        // 도착 및 무한 루프 판정
        if (Vector3.Distance(transform.position, targetPoint.position) < 0.1f)
        {
            currentIdx++;
            if (currentIdx >= path.Count)
            {
                currentIdx = 0; // 맵 끝에 도착하면 다시 0번 점을 향해 출발!
            }
        }
    }

    // 내가 지워질 때 내 마커들도 같이 청소
    private void OnDestroy()
    {
        foreach (var marker in myMarkers)
        {
            if (marker != null) Destroy(marker);
        }
    }
}
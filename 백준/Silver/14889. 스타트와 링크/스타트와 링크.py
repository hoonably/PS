import sys

N = int(sys.stdin.readline())
score = []
for _ in range(N):
    score.append(list(map(int, sys.stdin.readline().split())))

# True면 스타트팀 선수
visited = [False]*N

answer = sys.maxsize

# n단계
def backtracking(n, idx):
    global answer
    # 팀 구성이 완료되었으면
    if n==N//2:
        #점수 추가하기
        start = 0
        rink = 0
        for i in range(N):
            # 중첩 방지
            for j in range(i+1, N):
                # 둘 다 스타트팀
                if visited[i] and visited[j]:
                    start += score[i][j]+score[j][i]
                elif not visited[i] and not visited[j]:
                    rink += score[i][j]+score[j][i]
        # 점수차 역대 최소인지
        answer = min(answer, abs(start-rink))
        return

    # 모든 자식 노드에 대해
    # idx = 마지막에 팀에 넣은 idx
    # 여기서 idx부터 안해주면 불필요한 것을 탐색하므로 시간초과남.
    for i in range(idx, N):
        # 유망하다면 (스타트 팀에 없다면)
        if not visited[i]:
            visited[i]=True
            # 백트래킹(n+1)
            backtracking(n+1, i+1)
            # 부모노드로 이동
            visited[i]=False

backtracking(0,0)
print(answer)

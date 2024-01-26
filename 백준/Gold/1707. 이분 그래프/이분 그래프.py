import sys
from collections import deque

# bfs
def bfs(start):
    queue = deque([start])
    visited[start] = 0  # 시작 그룹 0으로 설정
    while queue:
        x = queue.popleft()  # 큐의 맨앞 원소를 빼낸다.

        for i in graph[x]:
            if visited[i] == -1:
                queue.append(i)
                visited[i] = visited[x] ^ 1  # 상위 정점과 다른 그룹으로 기록
            elif visited[i] == visited[x]:  # 같은 그룹이라면 바로 False
                return False

    return True


K = int(input())

for _ in range(K):
    V, E = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(V + 1)]
    visited = [-1] * (V + 1)  # 방문한 정점 체크

    for _ in range(E):
        a, b = map(int, sys.stdin.readline().split())
        # 무방향 그래프 생성
        graph[a].append(b)
        graph[b].append(a)

    result = True
    for i in range(1, V + 1):
        if visited[i] == -1:
            result = bfs(i)
            if not result:  # False 나오면 바로 종료
                break
    print('YES' if result else 'NO')

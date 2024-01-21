import sys
from collections import deque

def bfs(graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    n, m = len(graph), len(graph[0])
    dist = 0
    queue = deque()

    # 처음부터 익은것을 queue에 넣어주기
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                queue.append((i, j, 0))

    while queue:
        x, y, dist = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:  # 배열 범위 내에 있는지
                if graph[nx][ny] == 0:  # 갈 수 있다면
                    graph[nx][ny] = 1
                    queue.append((nx, ny, dist + 1))  # (다음좌표x, 다음좌표y, 현재거리 + 1)

    return dist  # 걸린 시간


M, N = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N)]
for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().split()))

# bfs 시작
time = bfs(graph)

# 다 돌았는데 그래프에 0이 남아있다면 토마토 모두 못 익음
for i in graph:
    if 0 in i:
        print(-1)
        exit()

print(time)

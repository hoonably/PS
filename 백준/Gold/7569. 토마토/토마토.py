import sys
from collections import deque

def bfs(graph):
    dx = [-1, 1, 0, 0, 0, 0]
    dy = [0, 0, -1, 1, 0, 0]
    dz = [0, 0, 0, 0, -1, 1]
    dist = 0
    queue = deque()

    # 처음부터 익은것을 queue에 넣어주기
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if graph[i][j][k] == 1:
                    queue.append((i, j, k, 0))

    while queue:
        x, y, z, dist = queue.popleft()

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if 0 <= nx < H and 0 <= ny < N and 0 <= nz < M:  # 배열 범위 내에 있는지
                if graph[nx][ny][nz] == 0:  # 갈 수 있다면
                    graph[nx][ny][nz] = 1
                    queue.append((nx, ny, nz, dist + 1))  # (다음좌표x, 다음좌표y, 현재거리 + 1)

    return dist  # 걸린 시간


M, N, H = map(int, sys.stdin.readline().split())
graph = [[[] for _ in range(N)] for _ in range(H)]
for i in range(H):
    for j in range(N):
        graph[i][j] = list(map(int, sys.stdin.readline().split()))

# bfs 시작
time = bfs(graph)

# 다 돌았는데 그래프에 0이 남아있다면 토마토 모두 못 익음
for i in graph:
    for j in i:
        if 0 in j:
            print(-1)
            exit()

print(time)

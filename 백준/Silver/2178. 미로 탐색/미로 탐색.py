import sys
from collections import deque

def bfs(start_x, start_y, end_x, end_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    n, m = len(graph), len(graph[0])

    visited = {(start_x, start_y)}  # 방문 집합 생성
    queue = deque([(start_x, start_y, 1)])  # 큐에 (x, y, 거리) 넣기

    while queue:
        x, y, dist = queue.popleft()

        if x == end_x and y == end_y:  # 탐색 종료
            return dist

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m: # 배열 범위 내에 있는지
                if (nx, ny) not in visited:
                    if graph[nx][ny] == 1: # 갈 수 있다면
                        visited.add((nx, ny))
                        queue.append((nx, ny, dist + 1))  # (다음좌표x, 다음좌표y, 현재거리 + 1)

    return -1  # 큐가 비었는데 도달 못했을 경우


N, M = map(int, sys.stdin.readline().split())
graph = [[0] * N for _ in range(N)]
for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().rstrip()))

print(bfs(0,0,N-1,M-1,graph))


import sys
from collections import deque

def bfs(start_x, start_y, end_x, end_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    n, m = len(graph), len(graph[0])

    visited = {(start_x, start_y, 1)}  # 방문 집합 생성 (x, y, 1)
    queue = deque([(start_x, start_y, 1, 1)])  # 큐에 (x, y, 벽부수는 남은 기회, 거리) 넣기

    while queue:
        x, y, chance, dist = queue.popleft()

        if x == end_x and y == end_y:  # 탐색 종료
            return dist

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m: # 배열 범위 내에 있는지
                if (nx, ny, chance) not in visited:
                    if graph[nx][ny] == 0: # 갈 수 있다면
                        visited.add((nx, ny, chance))
                        queue.append((nx, ny, chance, dist + 1))  # (다음좌표x, 다음좌표y, 남아있던 기회, 현재거리 + 1)

                    # 막혀있지만 부술 수 있다면
                    elif chance==1:
                        visited.add((nx, ny, 0))
                        queue.append((nx, ny, 0, dist + 1))  # (다음좌표x, 다음좌표y, 기회 0으로, 현재거리 + 1)

    return -1  # 큐가 비었는데 도달 못했을 경우


N, M = map(int, sys.stdin.readline().split())
graph = [[0] for _ in range(N)]
for i in range(N):
    # 띄어쓰기 없이 숫자를 입력받을 때는 rstrip 후 split(띄어쓰기 구분)하지말고 그냥 map int
    graph[i] = list(map(int, sys.stdin.readline().rstrip()))

print(bfs(0,0,N-1,M-1,graph))


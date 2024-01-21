import sys
from collections import deque

def bfs(start_x, start_y, end_x, end_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    n, m = len(graph), len(graph[0])

    # 이번엔 visited를 배열로 만들어야함.
    # visited[i][j][k] = i번 부숴서 j,k까지 갈 수 있는지 없는지
    visited = [[[False] * m for _ in range(n)] for _ in range(K+1)]
    visited[0][start_x][start_y] = True  # 첫번째 시작 방문

    queue = deque([(start_x, start_y, 0, 1)])  # 큐에 (x, y, 벽을 부순 기회, 거리) 넣기

    while queue:
        x, y, chance, dist = queue.popleft()

        if x == end_x and y == end_y:  # 탐색 종료
            return dist

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m: # 배열 범위 내에 있는지

                if graph[nx][ny] == 0 and visited[chance][nx][ny] == False:  # 갈 수 있다면
                    visited[chance][nx][ny] = True
                    queue.append((nx, ny, chance, dist + 1))  # (다음좌표x, 다음좌표y, 남아있던 기회, 현재거리 + 1)

                # 막혀있지만 찬스를 다 안써서 부술 수 있다면
                elif graph[nx][ny] == 1 and chance < K and visited[chance+1][nx][ny] == False:
                    visited[chance+1][nx][ny] = True
                    queue.append((nx, ny, chance + 1, dist + 1))  # (다음좌표x, 다음좌표y, 기회 0으로, 현재거리 + 1)

    return -1  # 큐가 비었는데 도달 못했을 경우


N, M, K = map(int, sys.stdin.readline().split())
graph = [[0] for _ in range(N)]
for i in range(N):
    # 띄어쓰기 없이 숫자를 입력받을 때는 rstrip 후 split(띄어쓰기 구분)하지말고 그냥 map int
    graph[i] = list(map(int, sys.stdin.readline().rstrip()))

print(bfs(0,0,N-1,M-1,graph))


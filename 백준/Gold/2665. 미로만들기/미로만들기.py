# 0-1 너비 우선탐색
# 다익스트라 알고리즘 중에서, 가는 비용이 0이 있는 경우
# deque의 popleft를 사용해서 다시 바로 탐색해주면 된다.
import sys
# 벽 부술 때는 비용이 1
# 빈 방으로 갈때는 비용이 0
# a에서 b로 가는 최단거리 구하기
from collections import deque

def bfs(start_x, start_y, end_x, end_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    n, m = len(graph), len(graph[0])

    visited = {(start_x, start_y)}  # 방문 집합 생성
    queue = deque([(start_x, start_y, 0)])  # 큐에 (x, y, 거리) 넣기

    while queue:
        x, y, dist = queue.popleft()

        if x == end_x and y == end_y:  # 탐색 종료
            return dist

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:  # 배열 범위 내에 있는지
                if (nx, ny) not in visited:
                    if graph[nx][ny] == 0:  # 검은 방이라면
                        visited.add((nx, ny))
                        queue.append((nx, ny, dist + 1))  # (다음좌표x, 다음좌표y, 현재거리 + 1)
                    else:  # 흰 방이라면 appendleft로 다음에 바로 탐색
                        visited.add((nx, ny))
                        queue.appendleft((nx, ny, dist))  # (다음좌표x, 다음좌표y, 현재거리)

    return -1  # 큐가 비었는데 도달 못했을 경우


n = int(sys.stdin.readline())
graph = []
for i in range(n):
    get_row = map(int, sys.stdin.readline().rstrip())
    graph.append(list(get_row))

print(bfs(0, 0, n-1, n-1, graph))

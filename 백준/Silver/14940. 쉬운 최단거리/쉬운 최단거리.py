import sys

from collections import deque

# 끝까지 완전탐색했을 때 visited return
def bfs(start_x, start_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    queue = deque([(start_x, start_y, 0)])

    while queue:
        x, y, depth = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < len(graph) and 0 <= ny < len(graph[0]):
                # 방문 안했다면
                if visited[nx][ny] == -1:
                    if graph[nx][ny] == 1:  # 갈 수 있다면
                        visited[nx][ny] = depth + 1
                        queue.append((nx, ny, depth+1))

    return visited

n, m = map(int, sys.stdin.readline().split())
graph = []
start_x, start_y = 0, 0
visited = [[-1] * m for _ in range(n)]

for i in range(n):
    get_row = list(map(int, sys.stdin.readline().split()))
    graph.append(get_row)
    for j in range(m):
        if get_row[j]==0:
            visited[i][j]=0
        elif get_row[j]==2:
            visited[i][j]=0
            start_x, start_y = i, j

visit = bfs(start_x, start_y, graph)
for row in visit:
    print(*row)

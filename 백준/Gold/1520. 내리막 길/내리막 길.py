import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
n, m = map(int, input().split())
graph = []

visited = [[-1] * m for _ in range(n)]
for _ in range(n):
    graph.append(list(map(int, input().split())))

moves = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def dfs(x, y):
    # 도달했을 경우
    if x == n - 1 and y == m - 1:
        return 1

    # 이미 방문한 곳일 때
    if visited[x][y] != -1:
        return visited[x][y]

    visited[x][y] = 0
    
    # 4가지 move
    for move in moves:
        nx, ny = x + move[0], y + move[1]

        if 0 <= nx < n and 0 <= ny < m:
            if graph[x][y] > graph[nx][ny]:
                visited[x][y] += dfs(nx, ny)

    return visited[x][y]

print(dfs(0, 0))
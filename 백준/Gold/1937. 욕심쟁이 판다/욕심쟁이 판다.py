import sys

sys.setrecursionlimit(10 ** 9)

def dfs(y, x):
    if visited[y][x]: # 방문했던거 나오면
        return visited[y][x]
    else:
        visited[y][x] = 1
        for dy, dx in move:
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < n:
                if maps[ny][nx] > maps[y][x]:
                    visited[y][x] = max(visited[y][x], dfs(ny, nx) + 1)
        return visited[y][x]


n = int(sys.stdin.readline())
maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]

move = [[-1, 0], [1, 0], [0, -1], [0, 1]]

ans = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            ans = max(ans, dfs(i, j))

print(ans)

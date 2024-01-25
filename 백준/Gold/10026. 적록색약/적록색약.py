import sys
sys.setrecursionlimit(10**6)

def dfs(x, y, color):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    visited[x][y] ^= 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < N:  # 배열 범위 내에 있는지
            if visited[nx][ny]==0 and graph[nx][ny]==color:
                dfs(nx, ny, color)  # (다음좌표x, 다음좌표y, 현재거리 + 1)

N = int(sys.stdin.readline())
graph = []
for _ in range(N):
    graph.append(list(sys.stdin.readline().rstrip()))
visited = [[0] * N for _ in range(N)]
ans = 0
for i in range(N):
    for j in range(N):
        if visited[i][j]==0:
            dfs(i, j, graph[i][j])
            ans+=1

# 적록색약 적용
for i in range(N):
    for j in range(N):
        if graph[i][j]=='R':
            graph[i][j]='G'

visited = [[0] * N for _ in range(N)]
ans2 = 0
for i in range(N):
    for j in range(N):
        if visited[i][j]==0:
            dfs(i, j, graph[i][j])
            ans2+=1

print(ans, ans2)

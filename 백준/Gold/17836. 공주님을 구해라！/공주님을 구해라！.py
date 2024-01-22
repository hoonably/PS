from collections import deque

n,m,t = map(int,input().split())

data = [list(map(int,input().split())) for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]
gram_dist = float("inf")
min_result = float("inf")

def bfs(i,j,visited):
    global gram_dist
    q = deque()
    q.append((i,j))
    visited[i][j] = 0
    while q:
        x,y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == -1:
                if data[nx][ny] == 0:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx,ny))
                if data[nx][ny] == 2:
                    gram_dist = ((n-1) - nx) + ((m-1) - ny) + visited[x][y] + 1
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx,ny))
                if nx == n -1 and ny == m - 1:
                    return min(visited[x][y] + 1, gram_dist)
    return gram_dist # 원래 -1이었는데 이렇게 바꿔주니 통과과 됐다. 이유가 뭘까....

visited = [[-1] * m for _ in range(n)]

min_result = bfs(0,0,visited)

if min_result > t:
    print("Fail")
else:
    print(min_result)
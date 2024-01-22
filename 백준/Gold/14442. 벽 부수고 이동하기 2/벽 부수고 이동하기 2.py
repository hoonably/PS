import sys
from collections import deque

def bfs():
    queue = deque([(0, 0, 1)])
    go = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    
    # visited = 그곳까지 도달했을때 최소로 벽 부순 횟수 저장
    visited = [[k+1]*m for _ in range(n)]
    visited[0][0] = 0  # 시작지점
    
    while queue:
        i, j, dist = queue.popleft()

        if (i, j) == (n-1, m-1):  # 도달
            return dist
        
        for di, dj in go:  # 4방향 이동
            ni, nj = i+di, j+dj
            if 0 <= ni < n and 0 <= nj < m:
                # n_destroy = 벽 부순 횟수
                n_destroy = board[ni][nj] + visited[i][j]  # 보드판이 1이면 1 더하기
                
                # 그곳까지 갔을때 최소 벽 부순 횟수보다 적으면 진행
                if n_destroy < visited[ni][nj]:
                    visited[ni][nj] = n_destroy
                    queue.append((ni, nj, dist+1))

    return -1

n, m, k = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]

print(bfs())

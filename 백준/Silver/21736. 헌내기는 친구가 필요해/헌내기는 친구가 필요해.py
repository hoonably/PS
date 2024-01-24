import sys
from collections import deque

def bfs(start_x, start_y, graph):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    visited = {(start_x, start_y)}  # 방문 집합 생성
    queue = deque([(start_x, start_y)])
    ans = 0  # 만난 사람 수

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < len(graph) and 0 <= ny < len(graph[0]):
                if (nx, ny) not in visited:
                    if graph[nx][ny] == 'P':  # 사람 만났다면
                        ans+=1
                        visited.add((nx, ny))
                        queue.append((nx, ny))
                    elif graph[nx][ny] == 'O':  # 사람도 아니고 벽도 아니면
                        visited.add((nx, ny))
                        queue.append((nx, ny))
    return ans

N, M = map(int, sys.stdin.readline().split())
graph = []
for _ in range(N):
    graph.append(list(sys.stdin.readline().rstrip()))

for i in range(N):
    for j in range(M):
        if graph[i][j]=='I':
            answer = bfs(i,j,graph)
            if answer != 0:
                print(answer)
            else:
                print('TT')
            quit()
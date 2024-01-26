import copy
import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(start_x, start_y, graph):

    wall = set()  # 만나는 벽 집합
    queue = deque([(start_x, start_y)])
    ans = 1  # 일단 본인 크기 1

    while queue:
        x, y = queue.popleft()

        for case in range(4):
            nx = x + dx[case]
            ny = y + dy[case]

            if 0 <= nx < len(graph) and 0 <= ny < len(graph[0]):
                if visited[nx][ny] == 0:
                    if graph[nx][ny] == 0:  # 갈 수 있다면
                        visited[nx][ny] ^= 1
                        ans += 1  # 색칠 크기 1 늘려주기
                        queue.append((nx, ny))
                    else:  # 벽이라면 집합에 저장
                        wall.add((nx, ny))

    # 탐색이 끝나면 wall의 좌표들의 값에 색칠한 크기 더해주기
    for x, y in wall:
        ans_graph[x][y] += ans
        ans_graph[x][y] %= 10  # 10으로 나눠서 저장

    return

N, M = map(int, sys.stdin.readline().split())
graph = [[0] for _ in range(N)]
for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().rstrip()))

# 깊은 복사
ans_graph = copy.deepcopy(graph)

# 방문 그래프 (벽 없는 곳만 체크할거임)
visited = [[0]*M for _ in range(N)]

for i in range(N):
    for j in range(M):
        # 색칠 안하고 벽이 아니라면
        if visited[i][j]==0 and graph[i][j]==0:
            visited[i][j] ^= 1
            bfs(i,j,graph)

for row in ans_graph:
    print("".join(map(str, row)))

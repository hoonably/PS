import sys
from collections import deque

def bfs(start_x, start_y, end_x, end_y, l):
    dx = [2, 2, -2, -2, 1, 1, -1, -1]
    dy = [1, -1, 1, -1, 2, -2, 2, -2]
    n, m = l, l

    visited = {(start_x, start_y)}  # 방문 집합 생성
    queue = deque([(start_x, start_y, 0)])  # 큐에 (x, y, 거리) 넣기

    while queue:
        x, y, dist = queue.popleft()

        if x == end_x and y == end_y:  # 탐색 종료
            return dist

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m: # 배열 범위 내에 있는지
                if (nx, ny) not in visited:
                    visited.add((nx, ny))
                    queue.append((nx, ny, dist + 1))  # (다음좌표x, 다음좌표y, 현재거리 + 1)

    return -1  # 큐가 비었는데 도달 못했을 경우

T = int(input())
for _ in range(T):
    l = int(input())
    start_x, start_y = map(int, sys.stdin.readline().split())
    end_x, end_y = map(int, sys.stdin.readline().split())
    print(bfs(start_x, start_y, end_x, end_y, l))


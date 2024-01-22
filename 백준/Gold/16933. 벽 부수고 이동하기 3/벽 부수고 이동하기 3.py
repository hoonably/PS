from collections import deque
import sys

def bfs(arr):
    # visited = 그곳까지 도달했을때 최소로 벽 부순 횟수 저장
    visited = [[k + 1] * m for _ in range(n)]
    visited[0][0] = 0
    direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque([(0, 0, 0)])  # (x, y, 여태까지 부순 횟수) 큐에 저장
    is_night = 0  # 첫 이동 낮 시작
    dist = 1
    while queue:

        # 현재 단계의 queue만큼 하고 dist, is_night 바꿔주기 위해서 for문 사용
        # 아니면 if문 매번 해줘야하거나 dist를 항상 큐에 넣어야함
        for _ in range(len(queue)):
            x, y, wall = queue.popleft()

            if x == n - 1 and y == m - 1:  # 종료
                return dist

            for dx, dy in direction:
                nx, ny = x + dx, y + dy

                if 0 <= nx < n and 0 <= ny < m:

                    # 기록된 visited보다 벽 부순 횟수가 적다면
                    if wall < visited[nx][ny]:

                        if arr[nx][ny] == '0':  # 벽이 없다면
                            queue.append((nx, ny, wall))
                            visited[nx][ny] = wall

                        elif wall < k:  # 벽이 있는데 부술 기회 남았다면
                            if is_night:  # 밤이면 가만히 있기
                                queue.append((x, y, wall))
                            else:  # 낮이면 부수고 기록
                                visited[nx][ny] = wall
                                queue.append((nx, ny, wall + 1))

        dist += 1
        is_night ^= 1  # 비트연산 XOR : 0,1 바꿔줌

    return -1

n, m, k = map(int, sys.stdin.readline().split())
board = [sys.stdin.readline().rstrip() for _ in range(n)]
print(bfs(board))

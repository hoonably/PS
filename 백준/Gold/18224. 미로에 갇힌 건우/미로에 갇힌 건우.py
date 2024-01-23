from collections import deque
import sys

def bfs(arr):
    # visited = 하루 바뀌고 걸린 시간 (0~2m-1)에 그 곳에 도달했었는지
    visited = [[[False] * n for _ in range(n)] for _ in range(2*m)]
    direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque([(0, 0)])  # (x, y, 여태까지 부순 횟수) 큐에 저장
    is_night = 0  # 첫 이동 낮 시작
    dist = 0
    while queue:

        mod = dist % (2*m)  # 낮밤 바뀌고 걸린 시간 (나머지)

        # 테스트 코드

        # print()
        # print("is_night:", is_night, "mode: ", mod, queue)
        # for i in range(2*m):
        #     print(i)
        #     for arr2 in visited[i]:
        #         print(arr2)

        # 현재 단계의 queue만큼 하고 dist, is_night 바꿔주기 위해서 for문 사용
        # 아니면 if문 매번 해줘야하거나 dist를 항상 큐에 넣어야함
        for _ in range(len(queue)):
            x, y = queue.popleft()

            if x == n - 1 and y == n - 1:  # 종료
                day = dist//(2*m) + 1
                time = 'moon' if is_night else 'sun'
                print(day, time)
                return

            for dx, dy in direction:
                nx, ny = x, y

                if is_night: # 밤인 경우
                    while True: # 뛰어넘기 가능
                        nx, ny = nx + dx, ny + dy
                        if 0 <= nx < n and 0 <= ny < n and not visited[mod][nx][ny]:
                            if arr[nx][ny] == 0:
                                visited[mod][nx][ny] = True
                                queue.append((nx, ny))
                                break
                        else:
                            break

                else:  # 낮인 경우
                    nx, ny = nx + dx, ny + dy
                    if 0 <= nx < n and 0 <= ny < n and not visited[mod][nx][ny]:
                        if arr[nx][ny] == 0:
                            visited[mod][nx][ny] = True
                            queue.append((nx, ny))

        dist += 1
        if dist % m == 0:
            is_night ^= 1  # 비트연산 XOR : 0,1 바꿔줌

    print(-1)
    return

n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
bfs(board)

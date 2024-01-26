import sys
from collections import deque

a, b = map(int, sys.stdin.readline().split())
if a >= b:
    print(a-b)
    quit()

limit = 100001
time = [0] * limit


def bfs(x, y):
    q = deque()
    q.append(x)

    while q:
        x = q.popleft()

        if y == x: # 도달
            return time[x]

        for nx in (x - 1, x + 1, x * 2):
            # 범위 안이고 아직 시간 기록 안했다면
            if 0 <= nx < limit and time[nx] == 0:
                if nx == 2 * x:
                    time[nx] = time[x]  # 시간 똑같이 기록
                    q.appendleft(nx)  # 시간이 똑같으니까 left에 append
                else:
                    time[nx] = time[x] + 1  # 시간 + 1
                    q.append(nx)

# 0일 경우에는 1로 이동하는거 +1 해주고 1을 시작으로 탐색
# 안그러면 2를 무한번 곱해줄 수 있음
if a == 0:
    print(bfs(1, b) + 1)
else:
    print(bfs(a, b))
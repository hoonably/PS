# 어려움

import sys

N = int(input())

# arr 특별하게 받기
arr = [0]*(N+1)
arr[0], arr[1] = map(int, sys.stdin.readline().split())
for i in range(2, N+1):
    _, arr[i] = map(int, sys.stdin.readline().split())

dp = [[0] * N for _ in range(N)]

# step = 몇개씩 비교할건지
for step in range(1,N):
    for loc in range(N-step):
        end = loc + step
        mul = arr[loc] * arr[end+1]
        # minimum = sys.maxsize
        # for k in range(loc, end):
        #     yk = dp[loc][k]
        #     xk = dp[end][k + 1]
        #     sz = arr[k + 1]
        #     total = yk + xk + sz * mul
        #     minimum = min(minimum, total)

        # zip 사용
        minimum = min(yk + xk + sz * mul for yk, xk, sz in zip(dp[loc][loc:end], dp[end][loc+1:end+1], arr[loc+1:end+1]))


        # 양쪽 다 해주기
        dp[loc][end] = dp[end][loc] = minimum

print(dp[0][-1])

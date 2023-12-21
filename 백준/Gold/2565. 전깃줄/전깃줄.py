import sys

n = int(sys.stdin.readline())
line = []
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    line.append((a,b))

line.sort()

dp = [1]*n
for i in range(1, n):
    for j in range(i):
        # i보다 앞순서의 도착지점이 더 작은지 체크
        if line[j][1] < line[i][1]:
            # dp 업데이트
            dp[i] = max(dp[i], dp[j]+1)

print(n-max(dp))

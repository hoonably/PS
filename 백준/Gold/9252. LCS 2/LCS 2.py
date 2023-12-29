import sys

a = list(sys.stdin.readline().rstrip())
b = list(sys.stdin.readline().rstrip())

n = len(a)
m = len(b)

dp = [[""] * (m + 1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + a[i-1]
        else:
            if len(dp[i-1][j]) >= len(dp[i][j-1]):
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i][j-1]


print(len(dp[-1][-1]))
if dp:
    print(dp[-1][-1])
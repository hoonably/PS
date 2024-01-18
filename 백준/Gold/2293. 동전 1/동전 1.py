import sys

input = sys.stdin.readline

n, k = map(int, input().split())

coins = []
for i in range(n):
    coins.append(int(input()))
coins.sort()

dp = [0] * (k + 1)
dp[0] = 1
for c in coins:
    # 그 코인을 사용하여 k까지 만들 수 있는 경우의 수
    for i in range(c, k + 1):
        dp[i] += dp[i - c]

print(dp[k])

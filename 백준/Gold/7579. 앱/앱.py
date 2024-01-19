import sys

N, M = map(int, sys.stdin.readline().split())
memory = [0] + list(map(int, sys.stdin.readline().split()))

# 비용 (cost)
cost = [0] + list(map(int, sys.stdin.readline().split()))

# 길이: 총 비용의 합
length = sum(cost)+1

# dp[i][j] = k
# j만큼 비용이 들었을때 k만큼의 메모리를 줄일 수 있음
dp = [[0 for _ in range(length)] for _ in range(N+1)]

ans = 10001 # 비용 최댓값 100 * 100 이므로

for i in range(1, N+1):
    ci, mi = cost[i], memory[i]
    # 일단 그 전 단계로 채우기
    for j in range(length):
        dp[i][j] = dp[i-1][j]

    # 들어가는 비용 ~ 비용의 합 까지 반복
    for j in range(ci, length):
        dp[i][j] = max(dp[i-1][j-ci] + mi, dp[i][j])

        # 정리된 메모리 >= M 이라면
        if dp[i][j] >= M:
            # 들어간 비용 vs 정답 (뭐가 더 작은가?)
            ans = min(ans, j)

# for i in dp:
#     print(i)
print(ans)

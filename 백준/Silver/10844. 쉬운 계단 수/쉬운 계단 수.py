# dp[n][m] = 길이가 n이고 마지막 자리가 m일 때의 갯수

N = int(input())
dp = [[0]*10 for _ in range(N+1)]

dp[1] = [1]*10
# 첫번째 자리수가 0이면 취급 안함
dp[1][0] = 0

for i in range(2, N+1):

    for j in range(10):

        # 마지막 자리가 0이 되려면 그 전 자리는 1이어야함
        if j==0:
            dp[i][0] = dp[i-1][1]

        # 마지막 자리가 9가 되려면 그 전 자리는 8
        elif j==9:
            dp[i][9] = dp[i-1][8]

        # 마지막 자리가 1~8 이라면 그 전 자리가 +-1 두가지 가능
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[-1])%1000000000)
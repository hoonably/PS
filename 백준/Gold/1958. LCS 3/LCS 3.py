import sys

# 각 문자열 입력
first = sys.stdin.readline().rstrip()
second = sys.stdin.readline().rstrip()
third = sys.stdin.readline().rstrip()

# DP 테이블 초기화
dp = [[[0] * (len(third)+1) for _ in range(len(second)+1)] for _ in range(len(first)+1)]

# LCS 진행
for i in range(1, len(first)+1):
    for j in range(1, len(second)+1):
        for k in range(1, len(third)+1):

            # 3개의 문자가 같을 경우
            if (first[i-1] == second[j-1] == third[k-1]):
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1
            # 다를 경우
            else:
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])

print(dp[-1][-1][-1])

import sys

n = int(sys.stdin.readline())
dp=[]
for _ in range(n):
    dp.append(list(map(int, sys.stdin.readline().split())))

for i in range(1, n):
    # 맨 앞 인덱스라면
    dp[i][0]=dp[i-1][0]+dp[i][0]
    # 중간이라면 위의 두개에서 내려옴
    for j in range(1, i):
        dp[i][j]= max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j]
    # 맨 뒤 인덱스라면
    dp[i][-1]=dp[i-1][-1]+dp[i][-1]

# 마지막 줄에서 최대값
print(max(dp[-1]))
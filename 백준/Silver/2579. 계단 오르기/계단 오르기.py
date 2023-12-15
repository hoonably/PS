import sys

n = int(sys.stdin.readline())
stair = [0]*301 # 0~300 인덱스
for i in range(1, n+1):
    stair[i] = int(sys.stdin.readline())

dp = [0]*301
dp[1]=stair[1]
dp[2]=stair[1]+stair[2]
dp[3]=max(stair[1]+stair[3], stair[2]+stair[3])

for i in range(4,n+1):
    # 이전에 두칸 뛰고 한칸 뛴 경우
    jump21 = dp[i - 3] + stair[i - 1] + stair[i]
    # 이전에 한칸 뛰고 두칸 뛴 경우
    jump12 = dp[i - 2] + stair[i]
    dp[i] = max(jump12, jump21)

print(dp[n])

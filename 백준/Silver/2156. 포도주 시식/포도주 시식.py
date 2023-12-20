import sys

n = int(sys.stdin.readline())
grape = [0]*10001 # 이거 (n+1)로 설정하면 틀린다. 뒤에 index error
for i in range(1, n+1):
    grape[i] = int(sys.stdin.readline())

dp = [0]*10001
dp[1]=grape[1]
dp[2]=grape[1]+grape[2]
dp[3]=max(dp[2], grape[1]+grape[3], grape[2]+grape[3])
for i in range(4,n+1):
    # 이전에 두칸 뛰고 한칸 뛴 경우
    jump21 = dp[i - 3] + grape[i - 1] + grape[i]
    # 이전에 한칸 뛰고 두칸 뛴 경우
    jump12 = dp[i - 2] + grape[i]
    dp[i] = max(jump12, jump21, dp[i-1])
    
# 계단 문제랑 다른 이유: 끝이 꼭 마지막일 필요가 없음
print(dp[n])
# 17626

n = int(input())
dp = [4] * (n+1)
dp[0], dp[1] = 0, 1
for i in range(2, n+1):
    
    # n보다 작은 제곱수들 : j의 제곱
    j = 1
    while (j**2) <= i:
        dp[i] = min(dp[i], dp[i-j**2])
        j += 1
    dp[i]+=1

print(dp[-1])

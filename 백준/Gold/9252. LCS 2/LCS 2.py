import sys

A = sys.stdin.readline().rstrip()
B = sys.stdin.readline().rstrip()

n, m = len(A), len(B)

dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(n):
    for j in range(m):
        if A[i]==B[j]:
            dp[i+1][j+1]=dp[i][j]+1
        else:
            dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j])

print(dp[-1][-1])

# 역추적
ans = ''
i, j = n, m
while i>0 and j>0:
    if dp[i][j]==dp[i][j-1]:
        j-=1
    elif dp[i][j]==dp[i-1][j]:
        i-=1
    else:
       ans = A[i-1] + ans
       i-=1
       j-=1

print(ans)

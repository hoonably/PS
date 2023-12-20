import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
dp = A.copy()
for i in range(N):
    for j in reversed(range(i)):
        if A[j]<A[i]:
            dp[i]= max(dp[j]+A[i],dp[i])

print(max(dp))

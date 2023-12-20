import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
dp = [1]*N
arr = [[A[i]] for i in range(N)]

for i in range(N):
    for j in reversed(range(i)):
        if A[j]<A[i]:
            if dp[j]+1>dp[i]:
                # 이전 수열에
                arr[i] = arr[j].copy()
                # 지금 수를 추가
                arr[i].append(A[i])
                # 갯수 표기
                dp[i] =dp[j]+1

best=max(dp)
longest_index = dp.index(best)
print(best)
print(*arr[longest_index])
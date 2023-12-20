import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
up = [1]*N
down = [1]*N

# i항까지 가장 많이 증가한 횟수
for i in range(N):
    for j in reversed(range(i)):
        if A[j]<A[i]:
            up[i]=max(up[i], up[j]+1)

# i항부터 가장 많이 감소한 횟수
for i in reversed(range(N)):
    for j in range(i+1,N):
        if A[j]<A[i]:
            down[i]=max(down[i], down[j]+1)

best = 0
for i in range(N):
    best = max(up[i]+down[i], best)

# 가장 큰 수는 중복되므로 제거
print(best-1)

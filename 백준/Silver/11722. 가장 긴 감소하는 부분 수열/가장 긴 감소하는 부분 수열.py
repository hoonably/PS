import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
down = [1]*N

# i항부터 가장 많이 감소한 횟수
for i in reversed(range(N)):
    for j in range(i+1,N):
        if A[j]<A[i]:
            down[i]=max(down[i], down[j]+1)

# 가장 큰 수는 중복되므로 제거
print(max(down))

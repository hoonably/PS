import sys

N, K = map(int, sys.stdin.readline().split())
A = [0] + list(map(int, sys.stdin.readline().split()))
S = [0]*(N+1)
# 1부터 N항까지의 합 리스트
for i in range(1, N+1):
    S[i]=S[i-1]+A[i]

max = -sys.maxsize
for i in range(K,N+1):
    check = S[i]-S[i-K]
    if check>max:
        max = check
print(max)
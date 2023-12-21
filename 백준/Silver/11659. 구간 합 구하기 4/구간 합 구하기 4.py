import sys

N, M = map(int, sys.stdin.readline().split())
A = [0] + list(map(int, sys.stdin.readline().split()))
S = [0]*(N+1)
for i in range(1, N+1):
    S[i]=S[i-1]+A[i]
for _ in range(M):
    start, end = map(int, sys.stdin.readline().split())
    print(S[end]-S[start-1])
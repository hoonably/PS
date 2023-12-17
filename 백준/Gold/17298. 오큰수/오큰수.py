import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = []
C = [-1]*N

for i in range(N):
    while B and A[i]>A[B[-1]]:
        C[B.pop()] = A[i]
    B.append(i)

print(*C)
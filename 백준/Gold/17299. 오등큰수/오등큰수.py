import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
F = [0]*1000001
B = []
C = [-1]*N

for a in A:
    F[a]+=1

for i in range(N):
    while B and F[A[i]]>F[A[B[-1]]]:
        C[B.pop()] = A[i]
    B.append(i)

print(*C)

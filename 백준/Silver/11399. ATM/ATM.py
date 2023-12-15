import sys

N = int(sys.stdin.readline())
P = list(map(int, sys.stdin.readline().split()))
P.sort()
answer = 0
for i in range(N):
    answer += (N-i)*P[i]
print(answer)
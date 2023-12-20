import sys

P = [0]*101
P[1],P[2],P[3],P[4],P[5]=1, 1, 1, 2, 2
for i in range(6, 101):
    P[i]=P[i-1]+P[i-5]

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    print(P[N])
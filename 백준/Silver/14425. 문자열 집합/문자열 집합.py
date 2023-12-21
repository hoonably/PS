import sys

N, M = map(int, input().split())
S = set()
count = 0

for _ in range(N):
    S.add(sys.stdin.readline())
for _ in range(M):
    check = sys.stdin.readline()
    if check in S:
        count+=1
print(count)
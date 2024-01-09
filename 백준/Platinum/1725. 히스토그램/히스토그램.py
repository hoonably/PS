# 스택을 이용한 풀이
import sys

N = int(sys.stdin.readline())
H = [0]*N
stack = []
best = 0

for i in range(N):
    H[i]=int(sys.stdin.readline())

for i in range(N):
    idx = i
    while stack and stack[-1][0] > H[i]:
        height, idx = stack.pop()
        S = (i-idx) * height
        best = max(best, S)

    # pop하지 않은 경우 인덱스 자기 자신 그대로
    # pop했다면 idx는 마지막으로 pop 된 인덱스 (거기까지 가능하므로)
    stack.append([H[i], idx])

temp=0
while stack:
    height, idx = stack.pop()
    S = (N - idx) * height
    best = max(best, S)


print(best)

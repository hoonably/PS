from collections import deque

N, K = map(int, input().split())
circle = deque(i+1 for i in range(N))
answer = []
while circle:
    for _ in range(K-1):
        circle.append(circle.popleft())
    answer.append(circle.popleft())

print('<', end='')
for i in range(len(answer)):
    if i<len(answer)-1:
        print(answer[i], end=', ')
    else:
        print(answer[i], '>', sep='')
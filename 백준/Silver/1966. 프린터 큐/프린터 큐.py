import sys
from collections import deque

T = int(sys.stdin.readline())
for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    doc_list = list(map(int, sys.stdin.readline().split()))
    p_list = deque()
    for i in range(N):
        p_list.append([doc_list[i], i])

    answer = 0
    while p_list:
        if p_list[0][0]==max(p_list, key=lambda x: x[0])[0]:
            answer += 1
            if p_list[0][1]==M:
                break
            p_list.popleft() # 출력
        else:
            p_list.append(p_list.popleft()) # 맨 뒷장으로
    print(answer)
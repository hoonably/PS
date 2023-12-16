import sys
from collections import deque

N, L = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

# 최소값으로 유망한 값만 남겨놓는 길이가 최대 L인 덱
slide = deque()

for i in range(N):
    new = A[i]

    # 첫번째 인덱스가 지금꺼 -L이면 지우기
    if slide and slide[0][0] == i-L:
        slide.popleft()

    # 기존에 있던 덱의 뒤부터 새로 넣는거보다 큰게 있으면 다 제거
    while slide:
        if slide[-1][1]>new:
            slide.pop()
        else:
            break # 무조건 덱에는 오름차순일테니 작거나 같다면 그 앞 인덱스는 확인할 필요가 없음

    # 새로운 값 대입
    slide.append((i, new))

    # 덱의 맨 앞은 자동으로 최소값이다.
    print(slide[0][1], end=' ')

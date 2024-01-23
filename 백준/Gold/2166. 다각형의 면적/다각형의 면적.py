# 신발끈 정리

# 변의 길이가 다른 다각형 넓이 구하는 공식을 사용하면 된다.
# 다각형의 좌표를 쓴다.
# 반시계 방향 순서로 x와 y좌표를 리스트로 나열한 후 첫 꼭지점의 좌표를 맨 마지막에 하나 더 추가해준다.
# 각 꼭지점의 x좌표를 다음 꼭지점 좌표의 y값과 곱한 후 각 결과들을 더한다. - 결과1
# 반대로 각 y좌표 값을 다음 x좌표 값들과 곱하여 각 결과들을 더해준다. - 결과2
# (결과2 - 결과1) / 2 하면 다각형의 넓이가 나온다.

import sys

N = int(input())
dot = []
for _ in range(N):
    dot.append(list(map(int, sys.stdin.readline().split())))

dot.append(dot[0])
plus = 0
minus = 0
for i in range(N):
    plus += dot[i][0]*dot[i+1][1]
    minus += dot[i][1]*dot[i+1][0]

S = abs(plus-minus)/2
print(round(S,1))
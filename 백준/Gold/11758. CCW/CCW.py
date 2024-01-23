# https://www.acmicpc.net/blog/view/27
import sys


def ccw(p1, p2, p3):
    p1_to_p2 = p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1]
    p2_to_p3 = p2[0]*p1[1] + p3[0]*p2[1] + p1[0]*p3[1]

    if p1_to_p2 - p2_to_p3 < 0:  # 시계방향
        return -1

    if p1_to_p2 - p2_to_p3 > 0:  # 반시계방향
        return 1

    return 0  # 평행

box = []
for i in range(3):
    box.append(list(map(int, sys.stdin.readline().split())))

print(ccw(box[0], box[1], box[2]))

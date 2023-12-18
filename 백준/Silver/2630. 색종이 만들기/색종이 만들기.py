# function F(x):
#   if F(x)가 간단 then:
#     return F(x)를 계산한 값
#   else:
#     x 를 x1, x2로 분할
#     F(x1)과 F(x2)를 호출
#     return F(x1), F(x2)로 F(x)를 구한 값
import sys


#2차원 리스트를 x1~x2-1, y1~y2-1 만큼 쪼개서 리턴해주는 함수
def list_cutting(array, x1, x2, y1, y2):
    new_list = []
    for i in range(x1, x2):
        new_list.append(array[i][y1:y2])
    return new_list

def counting(array):
    global white, blue
    if all(1 not in l for l in array):
        white += 1
        return
    if all(0 not in l for l in array):
        blue += 1
        return

    n = len(array)
    counting(list_cutting(array, 0, n // 2, 0, n // 2))
    counting(list_cutting(array, 0, n // 2, n // 2, n))
    counting(list_cutting(array, n // 2, n, 0, n // 2))
    counting(list_cutting(array, n // 2, n, n // 2, n))

N = int(sys.stdin.readline())
array = []
for _ in range(N):
    array.append(list(map(int, sys.stdin.readline().split())))
white = 0
blue = 0
counting(array)
print(white)
print(blue)
# 분할정복 사용
import sys

def max_square(l,r):
    # 밑변의 크기가 1인 직사각형
    if l==r:
        return H[l]

    # 가운데 분할선에 겹쳐있는 것 구하기
    m = (l+r)//2
    ml = m
    mr = m+1
    height = min(H[ml],H[mr])
    length = 2
    max_between = height * length


    while True:
        # 양쪽 다 끝까지 갔거나 0을 만난 경우
        if (H[ml] == 0 or ml==l) and (H[mr] == 0 or mr==r):
            break

        # 왼쪽이 끝까지 간 경우
        elif H[ml] == 0 or ml==l:
            mr+=1
            height = min(height, H[mr])

        # 오른쪽이 끝까지 간 경우
        elif H[mr] == 0 or mr==r:
            ml-=1
            height = min(height, H[ml])

        # 둘다 갈 수 있는 경우 중 왼쪽이 더 높은 경우
        elif H[ml-1]>H[mr+1]:
            ml-=1
            height = min(height, H[ml])

        # 둘다 갈 수 있는 경우 중 오른쪽이 더 높은 경우
        else:
            mr+=1
            height = min(height, H[mr])

        length+=1 # 길이 1 추가
        max_between = max(max_between, height*length) # 최대값 업데이트

    return max(max_square(l,m), max_square(m+1,r), max_between)

while True:
    H = list(map(int, sys.stdin.readline().split()))
    if H[0]==0:
        break
    print(max_square(1,H[0]))
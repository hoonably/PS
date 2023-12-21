import sys

# 미리 map으로 저장 후 dic에 넣기
_ = sys.stdin.readline()
N = map(int, sys.stdin.readline().split())
_ = sys.stdin.readline()
M = map(int, sys.stdin.readline().split())

dic_card = {}
for num in N:
    # 딕셔너리가 없다면 1로 생성
    if num not in dic_card:
        dic_card[num] = 1
    # 딕셔너리에 있다면 1 추가
    else:
        dic_card[num] += 1

for num in M:
    if num in dic_card:
        print(dic_card[num], end=' ')
    else:
        print(0, end=' ')

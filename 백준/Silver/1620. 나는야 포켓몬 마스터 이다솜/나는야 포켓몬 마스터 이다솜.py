import sys

dic_int_pok = {}
dic_pok_int = {}

# strip() : 양쪽 공백을 삭제
# lstrip() : 왼쪽 공백을 삭제
# rstrip() : 오른쪽 공백을 삭제

N, M = map(int, sys.stdin.readline().split())
for i in range(1, N+1):
    get_dic = sys.stdin.readline().strip()
    # 양방향 딕셔너리 생성
    dic_int_pok[i] = get_dic
    dic_pok_int[get_dic] = i


for _ in range(M):
    getA = sys.stdin.readline().strip()
    # 숫자인경우 .isdigit()를 사용하자.
    if getA.isdigit():
        print(dic_int_pok[int(getA)])
    else:
        print(dic_pok_int[getA])
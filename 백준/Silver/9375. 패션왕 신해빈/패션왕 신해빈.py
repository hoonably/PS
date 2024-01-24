import sys

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    clothes = {}  # 딕셔너리 생성
    for _ in range(n):
        _, kind = sys.stdin.readline().split()
        if kind in clothes:
            clothes[kind] += 1
        else:
            clothes[kind] = 1

    # 딕셔너리 value를 list로 변경
    value_list = list(clothes.values())

    # (a종류수 + 1) * (b종류수 + 1) * (c종류수 + 1)... - 1
    ans = 1
    for value in value_list:
        ans *= value + 1
    ans -= 1

    print(ans)

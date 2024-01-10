import sys

# 실패 테이블 생성
def kmptable(a):
    table = [0] * L
    j = 0
    for i in range(1, L):
        while j > 0 and a[i] != a[j]:
            j = table[j - 1]

        # 동일하면 j올리고 그 테이블을 j로
        if a[i] == a[j]:
            j += 1
            table[i] = j
    return table


L = int(sys.stdin.readline())
str = sys.stdin.readline().rstrip()

print(L - kmptable(str)[-1])

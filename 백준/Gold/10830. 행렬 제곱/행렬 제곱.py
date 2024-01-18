import sys

# 제곱을 구하는 분할정복
def power(a, n):
    if n == 1:
        # 1000일수 있기 때문에 그냥 a로 리턴하면 틀림
        temp = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(N):
                temp[i][j] = a[i][j] % 1000
        return temp
    elif n % 2 == 1:
        return multi(power(a, n - 1), a)
    else:
        return power(multi(a, a), n // 2)


# 행렬의 곱셈
def multi(a, b):
    temp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                temp[i][j] += a[i][k] * b[k][j]
                temp[i][j] %= 1000
    return temp

input = sys.stdin.readline

N, B = map(int, input().split())
matirx = []
for _ in range(N):
    matirx.append(list(map(int, input().split())))

for i in power(matirx,B):
    print(*i)

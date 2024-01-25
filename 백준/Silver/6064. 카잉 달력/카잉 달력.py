import sys

def calculate(m, n, x, y):
    k = x
    while k <= m * n:  # m*n을 넘으면 무한반복임

        # 둘다 각각 나누었을때 0이면 만족함
        if (k - x) % m == 0 and (k - y) % n == 0:
            return k

        k += m  #k-x가 m의 배수이기 때문에 k는 x로 초기화해주었기 때문에 m만 더해준다.
    return -1

t = int(input())

for _ in range(t):
    m, n, x, y = map(int, sys.stdin.readline().split())
    print(calculate(m, n, x, y))

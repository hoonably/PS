import sys

N = list(map(int, sys.stdin.readline().rstrip()))

# 0이 없으면 30의 배수가 아님
if 0 not in N:
    print(-1)

# 각 숫자의 자리수의 합이 3의 배수가 아니면 30의 배수가 아님
elif sum(N) % 3 != 0:
    print(-1)
else:
    N.sort(reverse=True)
    print(''.join(map(str, N)))
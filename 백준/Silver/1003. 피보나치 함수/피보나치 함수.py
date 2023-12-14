import sys

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    zero, one = 1, 0
    for _ in range(N):
        # zero는 이전꺼의 one이 된다.
        # one은 이전꺼의 합이 된다.
        zero, one = one, zero+one
    print(zero, one)
    
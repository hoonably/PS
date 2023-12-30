# DP 사용
import sys

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    row_1 = [0] + list(map(int, sys.stdin.readline().split()))
    row_2 = [0] + list(map(int, sys.stdin.readline().split()))

    # 1일때 예외처리
    if n==1:
        print(max(row_1[1], row_2[1]))
        continue

    dp_1 = [0] * (n + 1)
    dp_2 = [0] * (n + 1)
    for i in range(1,n+1):
        dp_1[i] = max(dp_2[i-1], dp_1[i-2], dp_2[i-2]) + row_1[i]
        dp_2[i] = max(dp_1[i - 1], dp_1[i - 2], dp_2[i - 2]) + row_2[i]
    answer = max(dp_1[-1], dp_1[-2], dp_2[-1], dp_2[-2])
    print(answer)

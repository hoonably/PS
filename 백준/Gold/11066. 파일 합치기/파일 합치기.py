# pypy3 제출시 통과 python3 시간초과

import sys

T = int(sys.stdin.readline())
for _ in range(T):
    K = int(sys.stdin.readline())
    chapter = [0] + list(map(int, sys.stdin.readline().split()))

    # 누적합 리스트
    # 누적합은 무조건 더해지고, 거기서 더 더해지는걸 더하면 되므로
    s_ch = [0 for _ in range(K+1)]
    for i in range(1,K+1):
        s_ch[i] = s_ch[i-1] + chapter[i]

    # dp[i][j]: i부터 j까지 합치는데 드는 최소 비용
    dp = [[0 for i in range(K + 1)] for j in range(K + 1)]

    for i in range(2, K+1):
        for j in range(1, K+2-i):
            # 1번 이외에 더 더해지는 것들의 최솟값 + 기본으로 들어가는 누적 합
            dp[j][j+i-1] = (min([dp[j][j+q] + dp[j+q+1][j+i-1] for q in range(i-1)])
                            + (s_ch[j+i-1] - s_ch[j-1]))

    # TEST
    # for arr in dp:
    #     print(arr)

    print(dp[1][K])

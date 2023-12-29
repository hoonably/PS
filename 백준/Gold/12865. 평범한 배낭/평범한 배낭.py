import sys

N, K = map(int, sys.stdin.readline().split())

stuff = [[0,0]]
# x축엔 가방 1~K 까지의 무게, y축은 물건 N개 개수
knapsack = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

# 물건 받기
for _ in range(N):
    getStuff = list(map(int, sys.stdin.readline().split()))
    stuff.append(getStuff)

for i in range(1, N + 1):
    for j in range(1, K + 1):
        weight = stuff[i][0]
        value = stuff[i][1]

        # 넣으려는 무게가 더 큰 경우
        if j < weight:
            # 위의 값을 그대로 가져옴
            knapsack[i][j] = knapsack[i - 1][j]

        # 넣어도 되는 경우
        else:
            # 넣어서 나온 값 vs 위의 값 그대로 비교
            knapsack[i][j] = max(value + knapsack[i - 1][j - weight], knapsack[i - 1][j])

print(knapsack[N][K])

import sys

N = int(sys.stdin.readline())

# money[집][RGB가격]
money = []

for i in range(N):
    money.append(list(map(int,sys.stdin.readline().split())))

# 마지막을 0~2색으로 칠했을 때 N번째 집까지의 비용의 최솟값
for i in range(1,N):
    for j in range(3):
        # 전에 다른 색들로 했을때의 최소값 + 지금 색 가격
        money[i][j] = min(money[i-1][j-1], money[i-1][j-2]) + money[i][j]

print(min(money[N-1][0], money[N-1][1], money[N-1][2]))
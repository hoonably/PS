import sys

N, K = map(int, input().split())
coin_list = [0]*N
for i in range(N):
    coin_list[i] = int(sys.stdin.readline())

needed_coin = 0
for coin in reversed(coin_list):
    needed_coin += K//coin
    K %= coin

print(needed_coin)
def get_money():
    dice = list(map(int, input().split()))
    dice.sort()
    if dice[0] == dice[1] == dice[2]:
        return 10000 + dice[0] * 1000
    elif dice[0] == dice[1]:
        return 1000 + dice[0] * 100
    elif dice[1] == dice[2]:
        return 1000 + dice[1] * 100
    else:
        return dice[2] * 100

money = []
N = int(input())
for i in range(N):
    money.append(get_money())
money.sort()
print(money[N-1])
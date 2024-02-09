now = 0
best = 0
for _ in range(4):
    o, i = map(int, input().split())
    now -= o
    now += i
    if now>best:
        best = now
print(best)
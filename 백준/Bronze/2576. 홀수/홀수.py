sum = 0
best_small = 100

for _ in range(7):
    n = int(input())
    if n%2==1:
        sum += n
        if n<best_small:
            best_small = n

if best_small==100:
    print(-1)
else:
    print(sum)
    print(best_small)
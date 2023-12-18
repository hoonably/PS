best = 0
best_person = 0
for i in range(1,6):
    a, b, c, d = map(int, input().split())
    score = a+b+c+d
    if score > best:
        best = score
        best_person = i

print(best_person, best)



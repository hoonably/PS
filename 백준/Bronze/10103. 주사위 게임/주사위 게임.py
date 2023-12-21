roundnum = int(input())
scoreA = 100
scoreB = 100

for i in range(roundnum):
    a,b = map(int, input().split())
    if a>b:
        scoreB -= a
    elif a<b:
        scoreA -= b

print(scoreA)
print(scoreB)
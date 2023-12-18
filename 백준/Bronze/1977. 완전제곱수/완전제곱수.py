M = int(input())
N = int(input())

powerlist = []
for i in range(1,101):
    if M <= i**2 <= N:
        powerlist.append(i**2)

if(len(powerlist)==0):
    print(-1)
else:
    print(sum(powerlist))
    print(powerlist[0])
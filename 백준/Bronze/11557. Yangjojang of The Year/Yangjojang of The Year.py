T = int(input())
for _ in range(T):
    N = int(input())
    bestDrink = 0
    bestSchool = ''

    for _ in range(N):
        school, drink = input().split()
        drink = int(drink)
        if(drink>bestDrink):
            bestDrink=drink
            bestSchool=school
    print(bestSchool)

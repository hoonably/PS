scoreSum = 0
for i in range(5):
    getScore = int(input())
    if getScore<40:
        getScore=40
    scoreSum+=getScore
print(scoreSum//5)
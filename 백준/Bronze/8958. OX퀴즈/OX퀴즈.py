case = int(input())
for i in range(case):
    result = input()
    continuity = 0
    score = 0
    for j in result:
        if j=="O":
            continuity += 1
            score += continuity
        else:
            continuity = 0
    print(score)
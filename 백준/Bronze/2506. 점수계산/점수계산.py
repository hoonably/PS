case = int(input())
score_list = list(map(int, input().split()))

continuity = 0
score = 0

for i in score_list:
    if i==1:
        continuity += 1
        score += continuity
    else:
        continuity = 0
print(score)
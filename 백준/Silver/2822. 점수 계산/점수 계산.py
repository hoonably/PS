score_list = []
for _ in range(8):
    score_list.append(int(input()))

score_list1 = score_list.copy()
score_list1.sort()
score = 0
for i in range(3,8):
    score += score_list1[i]
print(score)

num_list = []
for i in range(3,8):
    num_list.append(score_list.index(score_list1[i])+1)
num_list.sort()
for num in num_list:
    print(num,end=" ")
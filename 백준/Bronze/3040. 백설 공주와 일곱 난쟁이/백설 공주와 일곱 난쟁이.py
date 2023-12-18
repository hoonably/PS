height_list = []
for _ in range(9):
    height_list.append(int(input()))


# 이중 for문을 한번에 중지시키기 위한 장치
check_break = False

for i in range(9):
    for j in range(i+1, 9):
        if sum(height_list)-height_list[i]-height_list[j] == 100:
            height_list.pop(j)
            height_list.pop(i)
            check_break = True
            break
    if check_break:
        break

for height in height_list:
    print(height)
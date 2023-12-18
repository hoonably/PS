#일부러 stirng으로 받자.
num = input()
num_list = []
for each_num in num:
    num_list.append(int(each_num))

# 거꾸로 정렬
num_list.sort(reverse=True)
for sorted_num in num_list:
    print(sorted_num, end='')
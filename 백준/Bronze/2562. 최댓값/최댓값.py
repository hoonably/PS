num_list = []
for _ in range(9):
    num_list.append(int(input()))
num_list1 = num_list.copy()
num_list1.sort()
big = num_list1[-1]
print(big)
print(num_list.index(big)+1)
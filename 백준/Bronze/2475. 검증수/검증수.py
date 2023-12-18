num_list = list(map(int, input().split()))
add = 0
for list in num_list:
    add += list**2
print(add%10)
N = int(input())
sum = 0
num_list = list(map(int, input().split()))
num_list.sort()
M = num_list[-1]

for num in num_list:
    num = num / M * 100
    sum += num
print(sum/N)
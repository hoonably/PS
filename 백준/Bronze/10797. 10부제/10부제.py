not_allow = int(input())
car_list = list(map(int, input().split()))

answer = 0
for i in car_list:
    if i==not_allow:
        answer+=1
print(answer)
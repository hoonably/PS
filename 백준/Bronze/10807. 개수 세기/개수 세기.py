N = int(input())
num_list = list(map(int, input().split()))
v = int(input())
answer = 0
for num in num_list:
    if num==v:
        answer+=1
print(answer)
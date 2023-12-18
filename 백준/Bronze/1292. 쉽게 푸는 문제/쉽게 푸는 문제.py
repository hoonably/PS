A, B = map(int, input().split())

num_list = []
n = 0 # 인덱스
m = 1 # 숫자

while n<B:
    for _ in range(m):
        num_list.append(m)
        n+=1
    m+=1

sum = 0
for i in range(A-1, B):
    sum+=num_list[i]

print(sum)
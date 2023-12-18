N, K = map(int, input().split())
num_list = []
i=1
# 제곱근 이용
while i**2<N:
    if N%i==0:
        num_list.append(i)
        num_list.append(N//i)
    i+=1

if i**2==N:
    num_list.append(i)

num_list.sort()

if K>len(num_list):
    print(0)
else:
    print(num_list[K-1])
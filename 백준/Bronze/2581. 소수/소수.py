M = int(input())
N = int(input())

# 모두 0인 리스트 생성
num_list = [0 for i in range(N+1)]

# 0과 1은 소수가 아니다
num_list[0], num_list[1] = 1, 1

for i in range(2,N+1):
    if num_list[i] == 0:
        n = 2*i
        while n<=N:
            # 소수의 배수는 합성수이므로 1로 변경
            num_list[n]=1
            n+=i

# 합 출력
add = 0
for i in range(M, N+1):
    if num_list[i] == 0:
        add += i

if add == 0:
    print(-1)
else:
    print(add)


# 최소값 출력
for i in range(M, N+1):
    if num_list[i] == 0:
        print(i)
        break
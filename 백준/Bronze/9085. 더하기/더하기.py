T = int(input())
for _ in range(T):
    N = int(input())
    sum_list = list(map(int, input().split()))
    print(sum(sum_list))
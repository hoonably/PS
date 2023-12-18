T = int(input())
for _ in range(T):
    num_list = list(map(int, input().split()))
    num_list.sort()
    print(num_list[-3])
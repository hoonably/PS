T = int(input())
for _ in range(T):
    even_list = []
    num_list = list(map(int, input().split()))
    for num in num_list:
        if num % 2 == 0:
            even_list.append(num)
    print(sum(even_list), min(even_list))
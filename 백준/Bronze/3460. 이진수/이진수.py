T = int(input())
for _ in range(T):
    n = int(input())
    num_list = []
    while n>0:
        if n%2==1:
            num_list.append(1)
        else:
            num_list.append(0)
        n //= 2
    for i in range(len(num_list)):
        if num_list[i] == 1:
            print(i, end=" ")

    print()
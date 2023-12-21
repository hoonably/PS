n = int(input())
for i in range(n):
    if i % 2 == 1:
        print(" ", end='')
    for _ in range(n):
        print("* ",end='')
    print()
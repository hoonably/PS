import sys

M = int(sys.stdin.readline())
add = 0
xor = 0
for _ in range(M):
    get_num = list(map(int,sys.stdin.readline().split()))
    if get_num[0]==1:
        add += get_num[1]
        xor ^= get_num[1]
    elif get_num[0]==2:
        add -= get_num[1]
        xor ^= get_num[1]
    elif get_num[0]==3:
        print(add)
    else:
        print(xor)
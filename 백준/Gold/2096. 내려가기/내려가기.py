import sys

N = int(sys.stdin.readline())

big = [0,0,0]
small = [0,0,0]

for _ in range(N):
    new_line = list(map(int, sys.stdin.readline().split()))
    new_big, new_small = [0,0,0], [0,0,0]
    new_big[0] = max(big[0], big[1]) + new_line[0]
    new_big[1] = max(big) + new_line[1]
    new_big[2] = max(big[1], big[2]) + new_line[2]
    new_small[0] = min(small[0], small[1]) + new_line[0]
    new_small[1] = min(small) + new_line[1]
    new_small[2] = min(small[1], small[2]) + new_line[2]
    big = new_big.copy()
    small = new_small.copy()

print(max(big), min(small))
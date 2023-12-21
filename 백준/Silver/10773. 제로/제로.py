import sys

K = int(input())
num_list = []

for _ in range(K):
    n = int(sys.stdin.readline())
    if n==0:
        num_list.pop()
    else:
        num_list.append(n)
print(sum(num_list))
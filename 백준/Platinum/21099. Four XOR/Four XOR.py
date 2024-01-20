import sys

n = int(input())
xor = set()
a = list(map(int, sys.stdin.readline().split()))

if n > 60:
    print('Yes')
    quit()

for i in range(n - 1):
    for j in range(i + 1, n):
        x = a[i] ^ a[j]
        if x in xor:
            print('Yes')
            quit()
        else:
            xor.add(x)

print('No')
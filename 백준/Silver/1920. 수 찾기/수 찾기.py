import sys

_ = sys.stdin.readline()
a = set(map(int, sys.stdin.readline().split()))
_ = sys.stdin.readline()
m = map(int, sys.stdin.readline().split())

for num in m:
    if num in a:
        print(1)
    else:
        print(0)
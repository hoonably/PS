import sys

t = int(input())
for _ in range(t):
    n = int(input())
    location = list(map(int, sys.stdin.readline().split()))
    print((max(location)-min(location))*2)
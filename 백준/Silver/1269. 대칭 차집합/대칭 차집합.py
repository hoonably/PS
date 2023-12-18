import sys

_ = sys.stdin.readline()
a = set(map(int, sys.stdin.readline().split()))
b = set(map(int, sys.stdin.readline().split()))

print(len(a)+len(b)-2*len(a&b))
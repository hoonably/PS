import sys

A,B = map(int, sys.stdin.readline().split())
C = int(input())
A = A + (C//60)
B = B + (C%60)
A += B // 60
A = A % 24
B = B % 60
print(A,B)
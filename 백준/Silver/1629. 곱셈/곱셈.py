# 분할정복 거듭제곱
import sys

def power(a,n):
    if n==1:
        return a % C
    elif n%2==1:
        return power(a, n-1) * a % C
    else:
        return (power(a, n//2) ** 2) % C

A, B, C = map(int, sys.stdin.readline().split())
print(power(A, B))

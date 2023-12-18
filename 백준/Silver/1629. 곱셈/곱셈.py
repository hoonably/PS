import sys

A, B, C = map(int, sys.stdin.readline().split())

# a의 b승을 c로 나누는 함수
def div_mul(a,b,c):
    if b==1:
        return a%c
    if b%2==0: # 제곱 차수가 짝수인 경우
        return (div_mul(a,b//2,c)**2) % c
    else: # 제곱 차수가 홀수인 경우
        return (div_mul(a,b//2+1,c)*div_mul(a,b//2,c)) % c

print(div_mul(A,B,C))

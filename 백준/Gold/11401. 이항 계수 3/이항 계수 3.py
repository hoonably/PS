import sys

N, K = map(int, sys.stdin.readline().split())
p = 1000000007


# 팩토리얼 함수 (나머지 연산 적용)
def factorial(n):
    ans = 1
    for i in range(2, n + 1):
        ans *= i
        ans %= p
    return ans


# 분할정복 거듭제곱
# A의 B제곱을 p로 나눈 나머지

def power(a,n):
    if n==1:
        return a % p
    elif n%2==1:
        return power(a, n-1) * a % p
    else:
        return (power(a, n//2) ** 2) % p


top = factorial(N)
bottom = factorial(N - K) * factorial(K) % p

# 페르마의 소정리
# p가 소수, a가 정수일 때
#
# a의 p제곱 ≡ a(modp)
#  (합동 : p로 나눈 나머지가 서로 같다.)
# 그 식의 양 변을 a의 제곱으로 나눠주면 된다.

# 페르마의 소정리 이용해서 조합 공식 곱셈 형태로 변형
print(top * power(bottom, p - 2) % p)

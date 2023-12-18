# n보다 작은 양의 정수 중에서 n과 서로소인 수 개수

# 주의 : 원래 오일러 피 함수에서는 n=1일때 1이지만,
# 가끔 문제에서 n보다 '작은' 서로소의 개수를 구하라고 할 수 있다.
# 그러면 if n==1: return 0 예외처리를 해주자.

n = int(input())

def euler_phi(n):
    result = n  # 초기값 설정

    # 2부터 루트n까지의 모든 소수 p에 대해
    for p in range(2, int(n**0.5) + 1):
        # n이 p의 배수이면
        if n % p == 0:
            # result에서 (result / p)를 뺀다 (p의 배수가 다 사라지므로)
            result -= result // p
            while n % p == 0:
                n //= p

    # n이 1이 아닌 소수인 경우
    if n > 1:
        result -= result // n

    return result

print(euler_phi(n))

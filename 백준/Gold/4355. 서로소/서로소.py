# 백준 4355 서로소
import sys

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

# 0이 입력되면 종료
while True:
    n = int(sys.stdin.readline())
    if n==0:
        break
    # 원래 오일러 피 함수에서는 n=1일때 1이지만,
    # 여기서는 n보다 작은 수이기 때문에 n=1일때 0 이다.
    if n==1:
        print(0)
        continue
    print(euler_phi(n))

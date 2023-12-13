def binomial_coefficient(N,K):
    answer = 1
    for i in range(N-K+1, N+1):
        answer *= i
    for i in range(1, K+1):
        answer //= i
    return answer

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    print(binomial_coefficient(M,N))

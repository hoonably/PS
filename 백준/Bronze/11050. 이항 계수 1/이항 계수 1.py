N, K = map(int, input().split())
answer = 1
for i in range(N-K+1, N+1):
    answer *= i
for i in range(1, K+1):
    answer //= i
print(answer)
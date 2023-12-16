import sys

n, m = map(int, sys.stdin.readline().split())

A = list(map(int, sys.stdin.readline().split()))
S = [0] * n

# 이거 안하고 이중 for문 사용시 시간초과 나옴
# C[i] = S에서 나온 나머지인 i가 몇개 있는지
C = [0] * m
answer = 0

# i번째 인덱스 까지의 합을 m으로 나눈 값들 저장
S[0] = A[0]%m # %m 안해주면 첫번째 수가 m을 넘었을때 이후에 (ArrayIndexOutOfBounds) 발생
for i in range(1, n):
    S[i] = S[i-1] + A[i]
    S[i] %= m

# C
for i in range(n):
    # 나머지가 0이면 바로 정답 += 1
    # 왜냐면 본인 하나로 가능하기 때문
    if S[i]==0:
        answer += 1
    C[S[i]] += 1

# nC2 Combination 조합 구하기
for i in range(m):
    if C[i] >= 2:
        answer += C[i]*(C[i]-1)//2

print(answer)
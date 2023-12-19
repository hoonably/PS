import sys

N = int(sys.stdin.readline())
length = list(map(int, sys.stdin.readline().split()))
oil_pay = list(map(int, sys.stdin.readline().split()))

# 스택을 사용하여 풀이
cheap = sys.maxsize
answer = 0

for i in range(N-1):
    # 여태까지중에 가장 싼 기름값
    cheap = min(cheap, oil_pay[i])
    # 더 싼 기름값이 나오기 전까지는 계속 그 기름값으로 다님
    answer += cheap * length[i]

print(answer)

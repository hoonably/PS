import sys

# 0 / 0 1 / 0 1 2
# 0 / 1 1 / 2 2 2

# 합 : 0 1 3 6 ---
# 합 : 0 2 6 12

N = int(sys.stdin.readline())
answer = 0
for i in range(N+1):
    answer += i*(i+1)/2
    answer += i*(i+1)

print(int(answer))
import sys

N = int(input())
string = sys.stdin.readline().rstrip()

if N <= 2:
    print(1)
    quit()

# i번쩨로 시작했을때 최대 길이
arr = [0]*N

if string[-2] != '0':
    arr[-2] = 2
if string[-1] != '0':
    arr[-1] = 1

for i in range(N-2):
    if int(string[i])==0:
        arr[i]=0
        continue

    if int(string[i:i+3]) > 641:
        arr[i]=2
    else:
        arr[i]=3

# dp[i] : i번째부터 끝까지 최소 인원수
dp = [sys.maxsize for _ in range(N+1)]
dp[-1] = 0

# 탑다운
for i in reversed(range(N)):
    for j in range(1, arr[i]+1): # 3이면 1,2,3 세번 돌음
        dp[i] = min(dp[i], 1 + dp[i+j])

print(dp[0])
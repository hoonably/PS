import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
S = sys.stdin.readline().rstrip()

# 진행되고 있을때 O가 몇번 나왔는지
count_O = 0
# 이전의 문자
last = ''
ans = 0

for i in range(2, M):
    if S[i-2]=='I' and S[i-1]=='O' and S[i]=='I':
        count_O += 1
    elif S[i-2]=='O' and S[i-1]=='I' and S[i]=='O':
        continue
    else:
        # 계속 진행된 0의 갯수 - (N-1) 더해주기
        ans += max(0, count_O-(N-1))
        count_O=0

ans += max(0, count_O-(N-1))

print(ans)
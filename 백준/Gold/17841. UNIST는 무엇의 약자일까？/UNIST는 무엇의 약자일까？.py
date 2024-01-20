# dp 반복문 사용 재귀 x

import sys

n = int(sys.stdin.readline())
m=n
P = []

for i in range(n):
    s = sys.stdin.readline().rstrip()

    # 미리 필요없는거 넣지 않기
    if not s[0] in "UNIST":
        m-=1
        continue
    P.append(s[:5])  # 어차피 5글자 이후로는 필요가 없음

# DP[i][j] : i번 문자열부터 UNIST의 j번째 부터 만드는 경우의 수
# DP[ ][5] = 1 : DP 탑다운을 위해서 설정
DP = [[0,0,0,0,0,1] for _ in range(m+1)]

for i in reversed(range(m)): # n-1 -> 0
    for j in reversed(range(5)): # 4-> 0
        DP[i][j] = DP[i + 1][j]
        for k in range(5 - j):
            if k >= len(P[i]): # 단어의 길이를 넘어서는거 방지
                break
            if "UNIST"[j + k] != P[i][k]: # 틀렸을 경우 break
                break

            DP[i][j] += DP[i + 1][j + k + 1] # 맞는 경우 탑다운 경우의수 더하기
            DP[i][j] %= 1000000007

# for i in DP:
#     print(i)
print(DP[0][0])

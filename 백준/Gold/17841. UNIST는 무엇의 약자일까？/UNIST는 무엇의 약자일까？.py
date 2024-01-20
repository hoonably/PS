import sys
sys.setrecursionlimit(10**6)

def sol(i, j):

    # 끝까지 다 완성시
    if j == 5:
        return 1

    # i가 n개의 단어 다 썼지만 못만들었을 경우
    if i == n:
        return 0

    # 중복 계산 방지
    if DP[i][j] != -1:
        return DP[i][j]

    # 탑다운 값 가져오기
    DP[i][j] = sol(i + 1, j)

    for k in range(5 - j): # j+k 는 항상 0~4

        # P 범위 넘어가면 break (P가 5글자 이내일때)
        if k >= len(P[i]):
            break

        # 틀리면 바로 종료
        if "UNIST"[j + k] != P[i][k]:
            break

        # 맞으면 탑다운으로 내려오기 전 경우의 수를 더하기
        DP[i][j] += sol(i + 1, j + k + 1)
        DP[i][j] %= 1000000007

    return DP[i][j]

n = int(sys.stdin.readline())
P = [''] * n
# DP[i][j] : i번 문자열부터 UNIST의 j번째 부터 만드는 경우의 수
DP = [[-1] * 5 for _ in range(n)]

for i in range(n):
    s = sys.stdin.readline().rstrip()
    P[i] = s[:5] # 어차피 5글자 이후로는 필요가 없음

print(sol(0, 0))

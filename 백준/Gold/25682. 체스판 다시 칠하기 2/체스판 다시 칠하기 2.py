import sys

N, M, K = map(int, sys.stdin.readline().split())
A = []
for i in range(N):
    get_row = list(sys.stdin.readline().rstrip())
    A.append(get_row)

# 첫 시작 B
color = 'B'

def colorchange():
    global color
    if color == 'B':
        color = 'W'
    else:
        color = 'B'

# Sum[row][col] 2차원 배열
# : 0~y번 줄 0~x번까지 시작이 B일때 틀린것의 갯수
# 2차원 배열시 조심할 점
S = [[0 for j in range(M)] for i in range(N)]

for row in range(N):
    for col in range(M):
        if row==0 or col==0:
            S[row][col] = S[row-1][col] + S[row][col-1]
        else:
            S[row][col] = S[row-1][col] + S[row][col-1] - S[row-1][col-1]
        # 틀렸다면 1 추가
        if A[row][col]!=color:
            S[row][col] += 1
        colorchange()
    # M(가로)가 짝수면 줄이 바뀔때 다시 색 변경
    if M%2==0:
        colorchange()

best = sys.maxsize
for end_row in range(K-1,N):
    for end_col in range(K-1,M):
        check = S[end_row][end_col]
        if end_col-K>=0:
            check -= S[end_row][end_col - K]
        if end_row-K>=0:
            check -= S[end_row-K][end_col]
        if end_col-K>=0 and end_row-K>=0:
            check += S[end_row-K][end_col-K]
        # 기존의 최저값,
        # B로 시작일때 칠해야하는갯수 (check),
        # W로 시작할때 칠해야 하는 갯수 (K**2-check) 중 최솟값 구하기
        best = min(best, check, K**2-check)

print(best)
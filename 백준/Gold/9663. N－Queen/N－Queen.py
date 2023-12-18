# 첫번째 열에 1을 놓을때 -> 첫번째 열에 N을 놓을 때까지 backtracking 알고리즘을 사용한다.
'''
모든 경우는 좌우 대칭이다. -> 아직 안해줌
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
'''

def q_check(x):
    # 이미 기록된 0 ~ X-1 범위 보기
    for i in range(x):
        # row (가로)체크
        # 체크하려는 row == 기록된 row(q_list[i]) 일때 False
        if row[x] == row[i]:
            return False
        # 대각선 체크
        # 체크하려는 row 와 이미 기록된 row 의 차가
        # 체크하려는 column 과 기록된 column 의 차랑 같다면 대각선
        # abs() = 절댓값 함수
        if abs(row[x]-row[i]) == x-i:
            return False
    # 두 경우 다 피해가면 True
    return True


def n_queen(c):
    global answer

    # 끝까지 완성한 경우
    if c==N:
        answer+=1
        return

    for i in range(N):
        row[c] = i
        if q_check(c):
            n_queen(c+1)

N = int(input())
row = [0]*N
answer = 0
n_queen(0)
print(answer)
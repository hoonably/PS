import sys


def nqueen(depth):

    # depth가 N일 때 > 모든 퀸을 다 놓은 것
    if depth == N:
        print(*board)
        quit()

    if board[depth] != 0:
        nqueen(depth + 1)
        return

        # depth별 반복문
    for i in range(1,N+1):

        # 해당 depth를 visited 하지 않았을 때
        if visited[i] == False:
            temp = board[depth]
            board[depth] = i  # (depth, i)에 퀸 올리기
            if check(depth):
                visited[i] = True
                nqueen(depth + 1)  # 그 다음 열로 넘어감
                visited[i] = False  # 다시 false로 설정해 백트래킹
            board[depth] = temp


# 모든 열에 대해 퀸과 대각선, 좌우에 위치해 있는지 체크
def check(n):
    for i in range(N):
        if i==n:
            continue
        if board[i]==0:
            continue
        # 좌우에 있거나, 대각선에 있다면
        # TODO(여기서 기존 queen이 어떻게 적재되고 있는걸까?)
        if (board[n] == board[i]) or (abs(n - i) == abs(board[n] - board[i])):
            return False

    return True


# main
if __name__ == '__main__':
    N = int(input())  # dfs의 depth에 해당함
    # depth별 적재
    board = list(map(int, sys.stdin.readline().split()))
    visited = [False] * (N+1)
    for i in range(N):
        if board[i]!=0:
            visited[board[i]]=True

    nqueen(0)
    print(-1)
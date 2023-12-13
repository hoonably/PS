import sys
from collections import deque

N = int(sys.stdin.readline())

board = [[0]*N for _ in range(N)]

K = int(sys.stdin.readline())
for _ in range(K):
    x, y =map(int, sys.stdin.readline().split())
    board[x-1][y-1]=2

L = int(sys.stdin.readline())

move = deque()
for _ in range(L):
    a, b = sys.stdin.readline().split()
    a = int(a)
    move.append([a, b])

# 게임오버
def gameover():
    if x<0 or x>=N or y<0 or y>=N:
        return True
    # 몸통이 있는 자리라면
    if board[y][x]==1:
        return True

def turn(alphabet):
    global direction
    if alphabet == 'L':
        direction = (direction - 1) % 4
    elif alphabet == 'D':
        direction = (direction + 1) % 4

def moving(direction):
    global x, y
    if direction == 0:
        x+=1
    if direction == 1:
        y+=1
    if direction == 2:
        x-=1
    if direction == 3:
        y-=1


# x, y좌표 설정
x, y = 0, 0
time = 0
body = deque()
body.append([0,0])
direction = 0

while True:
    time+=1
    #이동
    moving(direction)

    # 무브에 남아있는게 있고 방향전환하는 시간이라면 방향전환
    if move and time == move[0][0]:
        turn(move[0][1])
        move.popleft()

    # 게임오버라면 시간 넣은 후 반복문 종료
    if gameover():
        print(time)
        break

    # 사과를 먹는다면
    if board[y][x] == 2:
        body.append([y,x])

    # 사과를 먹지 않는다면
    elif board[y][x] == 0:
        ty, tx = body.popleft()
        board[ty][tx] = 0
        body.append([y, x])

    # 몸통으로 저장
    board[y][x] = 1

    # 잘되는지 테스트 코드
    # for i in board:
    #     print(*i)


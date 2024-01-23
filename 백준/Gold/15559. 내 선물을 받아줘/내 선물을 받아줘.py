import sys
sys.setrecursionlimit(10**6)

def dfs(x,y,depth):
    global ans

    if board[x][y] == 'F':  # 현재 dfs경로 나오면
        ans+=1
        return
    if board[x][y] == 'T':  # 이전의 dfs경로 나오면
        return
    
    dx, dy = dic[board[x][y]]
    board[x][y] = 'F'  # 현재 dfs경로는 일단 F로 기록 (나중에 T로 바뀜)
    result = dfs(x+dx, y+dy, depth+1)  # 다음 진행상황의 탈출 여부
    board[x][y] = 'T'  # 탐색 모두 끝났다면 T로 변경

    return result


dic = {'N':(-1,0), 'E':(0,1), 'S':(1,0), 'W':(0,-1)}

N, M = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(M):
        if board[i][j]=='F' or board[i][j]=='T':  # 방문 했던거 나오면
            continue
        dfs(i,j,0)
        # for arr in board:
        #     print(arr)
        # print()

print(ans)

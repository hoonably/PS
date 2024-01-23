import sys
sys.setrecursionlimit(10**6)

dic = {'U':(-1,0), 'R':(0,1), 'D':(1,0), 'L':(0,-1)}

def dfs(x,y,depth):
    global ans
    if x==-1 or y==-1 or x==N or y==M:  # 탈출
        ans+=depth
        return True
    if board[x][y] == 'T':  # 탈출가능했던 경로 나오면
        ans+=depth
        return True
    if board[x][y] == 'F':  # 탈출불가능했던 경로 나오면
        return False

    # if visited[x][y]: # 이전꺼와는 안만나지만 지금이 무한반복이라면
    #     return False

    dx, dy = dic[board[x][y]]
    board[x][y] = 'F'  # 지금 상황에서 무한반복 방지
    result = dfs(x+dx, y+dy, depth+1)  # 다음 진행상황의 탈출 여부
    board[x][y] = ('T' if result else 'F')  # 다음 진행상황이 True라면 얘도 'T'로 기록

    return result

N, M = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(M):
        if board[i][j]=='T' or board[i][j]=='F':  # 방문 했던거 나오면
            continue
        dfs(i,j,0)
        # for arr in board:
        #     print(arr)
        # print()

print(ans)

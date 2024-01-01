N = int(input())
cnt = 0
row = [True]*N # 가로
x1 = [True]*(2*N) # 제일 왼쪽이 인덱스인 우상향 대각선
x2 = [True]*(2*N) # 제일 오른쪽이 인덱스인 우하향 대각선

def backtracking(n):
    global cnt
    # 다 도달했을 때 1카운트 후 종료
    if n==N:
        cnt+=1
        return

    for i in range(N):
        # 놓을 수 있으면
        if row[i] and x1[i+n] and x2[i+((N-1)-n)]:
            row[i]=False # 가로줄 제거
            x1[i+n]=False # 오른쪽 위 방향 대각선 제거
            x2[i+((N-1)-n)]=False # 오른쪽 아래 방향 대각선 제거

            # 자식 노드로 이동
            backtracking(n+1)

            # 백트래킹
            row[i]=True
            x1[i+n]=True
            x2[i+((N-1)-n)]=True

backtracking(0)
print(cnt)
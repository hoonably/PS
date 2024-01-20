import sys


def backtracking(n):

    # 다 도달했을 때
    if n==N:
        print(*arr)
        quit()

    # 이미 써있는경우 바로 다음단계로
    if arr[n] != 0:
        backtracking(n + 1)
        return

    for i in range(N):
        # 놓을 수 있으면
        if row[i] and x1[i+n] and x2[i+((N-1)-n)]:

            arr[n] = i+1
            row[i]=False # 가로줄 제거
            x1[i+n]=False # 오른쪽 위 방향 대각선 제거
            x2[i+((N-1)-n)]=False # 오른쪽 아래 방향 대각선 제거

            # 자식 노드로 이동
            backtracking(n+1)

            # 백트래킹
            row[i]=True
            x1[i+n]=True
            x2[i+((N-1)-n)]=True
            arr[n] = 0

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

row = [True]*N # 가로
x1 = [True]*(2*N) # 제일 왼쪽이 인덱스인 우상향 대각선
x2 = [True]*(2*N) # 제일 오른쪽이 인덱스인 우하향 대각선

for i in range(N):
    if arr[i] != 0:
        row[arr[i]-1] = False  # 가로줄 제거
        x1[arr[i]-1 + i] = False  # 오른쪽 위 방향 대각선 제거
        x2[arr[i]-1 + ((N - 1) - i)] = False  # 오른쪽 아래 방향 대각선 제거

backtracking(0)
print(-1)

import sys


def q_check(x):
    # 이미 기록된 0 ~ N 범위 보기
    for i in range(N):

        # 본인 단계 제외
        if i==x:
            continue

        # 아직 안쓴거는 대각선 영향갈수있으니 제외
        if row[i]==0:
            continue

        # row (가로)체크
        # 체크하려는 row == 기록된 row(q_list[i]) 일때 False
        if row[x] == row[i]:
            return False
        # 대각선 체크
        # 체크하려는 row 와 이미 기록된 row 의 차가
        # 체크하려는 column 과 기록된 column 의 차랑 같다면 대각선이니 False
        if abs(row[x]-row[i]) == abs(x-i): # abs() = 절댓값 함수
            return False
    # 두 경우 다 피해가면 True
    return True


def n_queen(n):
    # 끝까지 완성한 경우
    if n==N:
        print(*row)
        quit()

    # 이미 써있는경우 바로 다음단계로
    if row[n]!=0:
        n_queen(n+1)
        return

    # 1부터 N까지 넣어보기
    for i in range(1,N+1):
        # 해당 숫자를 사용하지 않았을 때만 넣기
        if visited[i] == False:
            temp = row[n]
            row[n] = i
            if q_check(n):
                visited[i]=True
                n_queen(n+1)
                visited[i]=False
            row[n] = temp

N = int(sys.stdin.readline())
row = list(map(int, sys.stdin.readline().split()))
visited = [False] * (N+1)
for i in range(N):
    if row[i] != 0:
        visited[row[i]] = True
n_queen(0)
print(-1)

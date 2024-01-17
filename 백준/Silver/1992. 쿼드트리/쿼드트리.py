import sys

N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().rstrip())))

# (x,y) 에서 시작하는 크기가 n인 쿼드트리
def quadtree(x, y, n):
    # 쿼드트리의 첫번째가 1인지 0인지
    check = arr[x][y]

    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                check = -1
                break

    if check == -1:
        print("(", end='')
        n = n // 2
        quadtree(x, y, n)  # 오른쪽 위
        quadtree(x, y + n, n)  # 왼쪽 위
        quadtree(x + n, y, n)  # 오른쪽 아래
        quadtree(x + n, y + n, n)  # 왼쪽 아래
        print(")", end='')

    elif check == 1:
        print(1, end='')

    else:
        print(0, end='')

quadtree(0, 0, N)

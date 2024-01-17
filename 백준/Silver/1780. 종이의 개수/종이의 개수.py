import sys

N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

ans = [0,0,0]

# (x,y) 에서 시작하는 크기가 n인 트리
def ninetree(x, y, n):
    # 트리의 첫번째가 1인지 0인지
    check = arr[x][y]

    for i in range(x, x + n):
        for j in range(y, y + n):
            if check != arr[i][j]:
                check = 100
                break

    if check == -1:
        ans[0]+=1

    elif check == 0:
        ans[1]+=1

    elif check == 1:
        ans[2]+=1

    else:
        n //= 3
        for i in range(3):
            for j in range(3):
                ninetree(x + i * n, y + j * n, n)

ninetree(0, 0, N)

print(ans[0])
print(ans[1])
print(ans[2])

M = int(input())
if M==1:
    print('*')
    quit()

# 2차원 배열 생성
star = [[' ' for _ in range(M*2)] for _ in range(M)]

def go(x, y, n):
    if n <= 3:
        for i in range(3):
            for j in range(i+1):
                # 왼쪽아래, 오른쪽 아래 별로 채우기
                star[x+i][y+j] = star[x+i][y-j] = '*'
        # 가운데 뻥 뚫어주기
        star[x+1][y] = ' '
        return
    m = n // 2
    # 위
    go(x, y, m)
    # 대각 왼쪽 아래
    go(x+m, y-m, m)
    # 대각 위쪽 아래
    go(x+m, y+m, m)

go(0, M-1, M)

# join을 사용해 공백 없이 2차원 배열 출력
for i in range(M):
    print(''.join(star[i]))

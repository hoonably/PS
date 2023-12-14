import sys

N, M, B = map(int, sys.stdin.readline().split())
field = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
answer = sys.maxsize
best_h = 0

for floor in range(257):
    exceed_block, lack_block = 0, 0

    for i in range(N):
        for j in range(M):
            # 땅을 캐는 경우
            if field[i][j] > floor :
                exceed_block += field[i][j] - floor
            # 땅을 만드는 경우
            else :
                lack_block += floor - field[i][j]

    # 블럭이 부족하지 않으면
    if exceed_block + B >= lack_block:
        # 시간이 최소라면
        # 답이 여러개라면 땅의 높이가 큰것을 출력해야하므로 '=' 포함
        if (exceed_block * 2) + lack_block <= answer:
            answer = (exceed_block * 2) + lack_block
            best_h = floor


print(answer, best_h)
import sys

# (r,c) 위치
# (0,0)(0,1)(0,2)...
# (1,0)(1,1)(1,2)...

# (r,c)에 n을 넣어도 되는지 판별
def s_check(r, c, n):
    # 그 자리 초기화 해야 한다!!! 아니면 그 자리에 있다고 할 수 있음
    sudoku[r][c]=0
    # row (가로)에 같은게 있는지 체크
    for i in range(9):
        if sudoku[r][i] == n:
            return False
    # column (세로)에 같은게 있는지 체크
    for i in range(9):
        if sudoku[i][c] == n:
            return False
    # 3x3 구역에 같은게 있는지 체크
    # 3칸씩 나눠서 구역을 하도록 설정
    for i in range(r//3*3, r//3*3+3):
        for j in range(c//3*3, c//3*3+3):
            if sudoku[i][j] == n:
                return False
    # 세 경우 다 아니면 True
    return True


def sol_sudoku(r,c):
    # 끝까지 완성한 경우
    # 2차원 리스트 원소 포함 여부
    if all(0 not in l for l in sudoku):
        for i in sudoku:
            for j in i:
                print(j,end='')
            print()
        # return이면 다른 답도 모두 출력하므로
        # 아예 프로그램을 종료시키는 quit()를 사용한다.
        quit()

    # column이 범위를 넘어가면 다음 row의 0번 column으로 이동
    if c>=9:
        c=0
        r+=1

    if sudoku[r][c]==0: # 비어있다면
        for n in range(1,10):
            #체크가 완료됐다면 넣기
            if s_check(r,c,n):
                sudoku[r][c] = n
                # 다음 단계 재귀
                sol_sudoku(r, c+1)
                # 다시 부모 단계로 돌아감
                sudoku[r][c] = 0
    else: #채워져있다면 그냥 다음 단계
        sol_sudoku(r,c+1)

sudoku = []
for _ in range(9):
    str = list(map(int,sys.stdin.readline().rstrip()))
    sudoku.append(str)

sol_sudoku(0, 0)

'''
예제만 맞을 수 있으니 이걸 대입해보자.
근데 이걸 대입하면 백트래킹을 안해도 맞을 수 있어서 다른 것도 대입해봐야된다.
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
'''
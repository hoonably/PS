import sys

def s_check(r, c, n):
    if (n in row[r]) or (n in column[c]) or (n in area[r//3*3 + c//3]):
        return False
    # 세 경우 다 아니면 True
    return True

def sol_sudoku(r,c):
    # 끝까지 완성한 경우
    # 2차원 리스트 원소 포함 여부
    if r==8 and c==9:
        for i in sudoku:
            print(*i)
        quit()

    # column이 범위를 넘어가면 다음 row의 0번 column으로 이동
    if c>=9:
        c=0
        r+=1

    # 이미 채워져있다면
    if sudoku[r][c]!=0:
        sol_sudoku(r, c + 1)
        return

    # 비어있다면 1부터 9까지 넣어보기
    for n in range(1,10):
        # 체크가 완료됐다면 넣기
        if s_check(r,c,n):
            sudoku[r][c] = n
            row[r].add(sudoku[r][c])
            column[c].add(sudoku[r][c])
            area[r // 3 * 3 + c // 3].add(sudoku[r][c])
            # 다음 단계 재귀
            sol_sudoku(r, c+1)
            # 다시 부모 단계로 돌아감
            row[r].remove(sudoku[r][c])
            column[c].remove(sudoku[r][c])
            area[r // 3 * 3 + c // 3].remove(sudoku[r][c])
            sudoku[r][c]=0

row = [set() for _ in range(9)] # 가로줄
column = [set() for _ in range(9)] # 세로줄
area = [set() for _ in range(9)] # 3x3 구역

sudoku = []
for _ in range(9):
    sudoku.append(list(map(int, sys.stdin.readline().split())))

for r in range(9):
    for c in range(9):
        row[r].add(sudoku[r][c]) # 가로줄
        column[c].add(sudoku[r][c]) # 세로줄
        area[r//3*3 + c//3].add(sudoku[r][c]) # 구역에 넣기

sol_sudoku(0, 0)

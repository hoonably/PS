import sys

# M 값이 클 수 있기 때문에 미리 (1,1) 부터 (x,y) 까지 사각형에 들어있는 합에 대한 배열을 생성해놓는다.

N, M = map(int, sys.stdin.readline().split())
arr = [[0]*(N+1)]
for _ in range(N):
    arr_row = [0] + list(map(int, sys.stdin.readline().split()))
    arr.append(arr_row)

'''
arr 
1 2 
2 3

D (사각합)
1 3
3 5 -> D[2][2]를 구하는 법 : D[2][1]  +  D[1][2]   - D[1][1] + A[2][2]
                        자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합 + 자기 자신
'''

D = [[0]*(N+1) for _ in range(N+1)] # N+1 * N+1 이차원 배열 설정

for i in range(1, N+1):
    for j in range(1,N+1):
        D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + arr[i][j]
#               자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합 + 자기 자신

for _ in range(M):
    x1, y1, x2,y2 = map(int, sys.stdin.readline().split())
    answer = 0
    print(D[x2][y2]-D[x2][y1-1]-D[x1-1][y2]+D[x1-1][y1-1])
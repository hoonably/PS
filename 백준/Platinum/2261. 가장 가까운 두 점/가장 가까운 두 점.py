import sys

n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))

# 일단 x좌표에 대해서 정렬을 해준다.
arr.sort()

# a번째 인덱스와 b번째 인덱스 사이의 거리의 제곱
def get_dist(a, b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2

# start, end는 인덱스를 나타낸다.
def solve(start, end):

    global best

    # 점이 1개
    if start==end:
        return float('inf')
    # 점이 2개
    if end-start==1:
        return get_dist(arr[start], arr[end])

    # 3개 이상이면 반으로 나눠서 분할정복 실행
    mid = (start+end)//2
    best = min(solve(start, mid), solve(mid,end))

    # 나눠지는 부분들 사이에 거리의 최소값을 구하는것

    #사이 array 설정
    bet_arr = []
    for i in range(start, end+1):
        mid = (start + end) // 2
        if (arr[mid][0] - arr[i][0])**2 < best:
            bet_arr.append(arr[i])

    # y축에 대해서 정렬
    bet_arr.sort(key=lambda x: x[1])

    # y축만 비교했을때 차이가 이미 best를 넘어가면 굳이 계산 할 필요가 없음
    # 그리고 한번 넘어가면 정렬을 해주었기 때문에 그 이후부터는 무조건 다 넘어감
    # 이렇게 안하면 시간 초과 발생
    t = len(bet_arr)
    for i in range(t - 1): # 좌표 1
        for j in range(i + 1, t): #좌표 2
            if (bet_arr[i][1] - bet_arr[j][1]) ** 2 < best:
                best = min(best, get_dist(bet_arr[i], bet_arr[j]))
            else:
                break
    return best

print(solve(0,n-1))
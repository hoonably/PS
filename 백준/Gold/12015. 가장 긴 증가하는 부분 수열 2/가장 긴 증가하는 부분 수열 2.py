import sys

# 이분 탐색 이용

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))

arr = [A[0]]

# 이분탐색
def findPlace(e):
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == e:
            return mid
        elif arr[mid] < e:
            start = mid + 1
        else:
            end = mid - 1
    return start


for item in A:
    # 마지막꺼보다 지금이 크면 추가
    if arr[-1] < item:
        arr.append(item)
    # 아닌 경우엔 자신이 사이에 들어갈 자리 탐색
    else:
        idx = findPlace(item)
        arr[idx] = item

print(len(arr))
import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
answer = 0

def merge_sort(arr):

    global answer

    if len(arr) < 2:
        return arr

    mid = len(arr) // 2
    # 재귀 호출
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])

    merged_arr = []
    l = h = 0

    merged_index = 0

    while l < len(low_arr) and h < len(high_arr):
        if low_arr[l] <= high_arr[h]:
            merged_arr.append(low_arr[l])
            merged_index += 1
            l += 1
        else:
            merged_arr.append(high_arr[h])
            answer += len(low_arr) + h - merged_index
            merged_index += 1
            h += 1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr

merge_sort(A)
print(answer)
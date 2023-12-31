import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
answer = 0

# 이 문제는 제목은 버블소트이지만 시간복잡도때문에 병합정렬을 이용해서 버블소트때 스왑한 횟수를 구하면 된다.


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
        # 값이 같을때는 스왑을 할 필요가 없기 때문에 <= 을 붙여줘야한다.
        if low_arr[l] <= high_arr[h]:
            merged_arr.append(low_arr[l])
            merged_index += 1
            l += 1
        else:
            merged_arr.append(high_arr[h])
            # 요기가 포인트다.
            # 뒷부분의 h 번째 (len(low_arr) + h)에서 새로운 배열의 merged_index 번째로
            # 한번에 몇칸 진행하는가에 대한 식이다.
            answer += len(low_arr) + h - merged_index
            merged_index += 1
            h += 1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr

merge_sort(A)
print(answer)
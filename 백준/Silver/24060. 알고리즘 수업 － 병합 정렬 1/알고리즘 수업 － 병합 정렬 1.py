def merge_sort(num_list):
    if len(num_list) == 1:
        return num_list

    # 이 문제에서는 홀수개를 나눌때 앞이 큰 쪽으로 나눈다.
    mid = (len(num_list) + 1) // 2

    left = merge_sort(num_list[:mid]) # 왼쪽 부분
    right = merge_sort(num_list[mid:]) # 오른쪽 부분

    i, j = 0, 0
    sorted_list = []
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            answer.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            answer.append(right[j])
            j += 1
    while i < len(left):
        sorted_list.append(left[i])
        answer.append(left[i])
        i += 1
    while j < len(right):
        sorted_list.append(right[j])
        answer.append(right[j])
        j += 1

    return sorted_list

N, K = map(int, input().split())
num_list = list(map(int, input().split()))
answer = []

merge_sort(num_list)

if len(answer)<K:
    print(-1)
else:
    print(answer[K-1])
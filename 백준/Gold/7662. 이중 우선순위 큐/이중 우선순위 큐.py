import heapq
import sys

T = int(input())
for _ in range(T):
    k = int(input())

    up_heap = []  # 오름차순 힙
    down_heap = []  # 내림차순 힙

    # Q에 남아있는 원소의 개수 딕셔너리
    dic = {}

    Q_length = 0
    for i in range(k):
        get_how, get_num = sys.stdin.readline().split()
        get_num = int(get_num)
        if get_how == 'I':
            # 최소 힙 만들기
            heapq.heappush(up_heap, get_num)
            # 최대 힙 만들기 - 나중에 [1]로 출력해주면 됨
            heapq.heappush(down_heap, (-get_num, get_num))

            if get_num not in dic:
                dic[get_num] = 1
            else:
                dic[get_num] += 1

            Q_length += 1

        elif Q_length == 0:  # 삭제해야하는데 Q가 비어있는 경우
            continue

        elif get_num == -1:  # 최솟값 삭제
            while True:
                pop = heapq.heappop(up_heap)
                if dic[pop] > 0:
                    dic[pop] -= 1
                    break

            Q_length -= 1


        else:  # 최댓값 삭제
            while True:
                pop = heapq.heappop(down_heap)[1]
                if dic[pop] > 0:
                    dic[pop] -= 1
                    break
            Q_length -= 1

    largest = None
    smallest = None
    for _ in range(len(down_heap)):
        largest = heapq.heappop(down_heap)[1]
        if dic[largest] > 0:
            break
    for _ in range(len(up_heap)):
        smallest = heapq.heappop(up_heap)
        if dic[smallest] > 0:
            break

    if Q_length == 0:
        print('EMPTY')
    elif largest is None and smallest is None:
        print('EMPTY')
    elif largest is None:
        print(smallest, smallest)
    elif smallest is None:
        print(largest,largest)
    else:
        print(largest, smallest)

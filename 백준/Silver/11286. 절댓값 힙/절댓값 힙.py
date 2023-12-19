import sys
import heapq

N = int(sys.stdin.readline())

# 음수 힙과 양수 힙을 만들어주자.
heap_plus = []
heap_minus = []

for _ in range(N):
    get_num = int(sys.stdin.readline())
    # 양수
    if get_num>0:
        heapq.heappush(heap_plus, get_num)
    # 음수
    elif get_num<0:
        heapq.heappush(heap_minus, -get_num)
    # 0
    else:
        #  힙이 비어있다면
        if len(heap_plus)+len(heap_minus)==0:
            print(0)
        elif len(heap_plus)==0 and len(heap_minus)!=0:
            print(-heapq.heappop(heap_minus))
        elif len(heap_plus)!=0 and len(heap_minus)==0:
            print(heapq.heappop(heap_plus))

        # 음수의 절대값이 양수보다 작거나 같은 경우
        elif heap_minus[0]<=heap_plus[0]:
            # 음수 pop 출력
            print(-heapq.heappop(heap_minus))
        # 양수의 절대값이 더 작은 경우
        else:
            print(heapq.heappop(heap_plus))
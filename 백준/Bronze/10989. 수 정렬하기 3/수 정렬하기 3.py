# 이 문제는 수의 개수가 많고 각 숫자의 크기가 크지 않다.
# 또한 메모리 제한이 8MB이기 때문에 메모리 사용에 주의해야 한다.
# for문 속에서 append를 사용하게 되면
# 메모리 재할당이 이루어져서 메모리를 효율적으로 사용못한다.

# 미리 리스트 만들어놓고 그 값에 따른 리스트값을 1씩 추가하는 카운팅 정렬

import sys

# 미리 최대 숫자 크기의 list를 만드는 방법 사용
N = int(sys.stdin.readline())
num_list = [0] * 10001
for _ in range(N):
    num = int(sys.stdin.readline())
    num_list[num]+=1

for i in range(len(num_list)):
    for _ in range(num_list[i]):
        print(i)

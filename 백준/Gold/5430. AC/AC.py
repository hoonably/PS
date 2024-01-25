import sys
from collections import deque

T = int(input())
for _ in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(input())
    x = sys.stdin.readline().rstrip()
    if x == '[]':
        x = deque()
    else:
        x = deque(map(int, x[1:-1].split(',')))

    check = True
    reverse_check = 0
    for do in p:
        if do == 'R':
            reverse_check ^= 1

        elif len(x)==0:  # D 하려는데 배열이 비어있다면
            check = False
            print('error')
            break

        elif reverse_check:  # 홀수번 뒤집혔다면
            x.pop()
        else:  # 짝수번 뒤집혔다면
            x.popleft()

    if check:
        if reverse_check:  # 홀수번 R이 있었다면
            x.reverse()  # deque 뒤집기
        print("[" + ",".join(map(str, x)) + "]")
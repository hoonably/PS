import sys

T = int(sys.stdin.readline())

for _ in range(T):

    N = int(sys.stdin.readline())
    print(N)
    print(' ', end='')

    col = 2
    if N % 6 == 2: # 6의 나머지가 2일때
        cnt = N - 4
        while cnt > 0:
            print(col-1, end=' ')
            col += 2
            if col > N:
                print(2, end=' ')
                print(0, end=' ')
                col = 7
            cnt -= 1
        print(col-1, end=' ')
        print(4, end=' ')

    elif N % 6 == 3: # 6의 나머지가 3일때
        col = 4
        cnt = N - 3
        while cnt > 0:
            print(col-1, end=' ')
            col += 2
            if col > N and col % 2 == 0:
                print(1, end=' ')
                col = 5
            cnt -= 1
        print(0, end=' ')
        print(2, end=' ')

    else: # 일반적인 케이스 (단순한 계단식)
        for i in range(1, N+1):
            print(col-1, end=' ')
            col += 2
            if col > N:
                col = 1
    print()
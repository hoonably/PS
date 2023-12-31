# 알고리즘의 출처 : https://en.wikipedia.org/wiki/Eight_queens_puzzle

N = int(input())

col = 2
if N % 6 == 2: # 6의 나머지가 2일때
    cnt = N - 4
    while cnt > 0:
        print(col)
        col += 2
        if col > N:
            print(3)
            print(1)
            col = 7
        cnt -= 1
    print(col)
    print(5)
    
elif N % 6 == 3: # 6의 나머지가 3일때 
    col = 4
    cnt = N - 3
    while cnt > 0:
        print(col)
        col += 2
        if col > N and col % 2 == 0:
            print(2)
            col = 5
        cnt -= 1
    print(1)
    print(3)
    
else: # 일반적인 케이스 (단순한 계단식)
    for i in range(1, N+1):
        print(col)
        col += 2
        if col > N:
            col = 1

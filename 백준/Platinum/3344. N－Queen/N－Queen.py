N = int(input())

'''
<백준 3344 N-Queen>

알고리즘의 출처 : https://en.wikipedia.org/wiki/Eight_queens_puzzle
위키 설명 읽고 그대로 코드로 옮겼습니다.
The examples above can be obtained with the following formulas.[3] Let (i, j) be the square in column i and row j on the n × n chessboard, k an integer.

One approach[3] is

1. If the remainder from dividing n by 6 is not 2 or 3 then the list is simply all even numbers followed by all odd numbers not greater than n.
2. Otherwise, write separate lists of even and odd numbers (2, 4, 6, 8 – 1, 3, 5, 7).
3. If the remainder is 2, swap 1 and 3 in odd list and move 5 to the end (3, 1, 7, 5).
4. If the remainder is 3, move 2 to the end of even list and 1,3 to the end of odd list (4, 6, 8, 2 – 5, 7, 1, 3).
5. Append odd list to the even list and place queens in the rows given by these numbers, from left to right (a2, b4, c6, d8, e3, f1, g7, h5).

****
5 이하의 수에 대해서는 잘 작동하지 않을 수 있습니다.
백준 3344번의 input 이 다 8 이상이기에 굳이 예외처리 하지 않았습니다.

'''
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

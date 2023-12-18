A, B = input().split()

# 문자열 뒤집기
A = int(A[::-1])
B = int(B[::-1])

if A>B:
    print(A)
else:
    print(B)
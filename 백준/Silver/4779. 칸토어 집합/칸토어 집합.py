import sys

def kantore(n):
    if n == 0:
        return '-'
    str = kantore(n-1) + (' ' * (3**(n-1))) + kantore(n-1)
    return str

while True:
    try :
        N = int(sys.stdin.readline())
        print(kantore(N))
    except : # EOF 발생시
        break # 종료
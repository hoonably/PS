import sys

N = int(sys.stdin.readline())

def check(str):
    stack = []
    for s in str:
        if s=='(':
            stack.append(0)
        elif s==')':
            if(len(stack)==0):
                return False
            else:
                stack.pop()
    if len(stack)==0:
        return True
    else:
        return False

for _ in range(N):
    str = sys.stdin.readline()
    if check(str):
        print('YES')
    else:
        print('NO')
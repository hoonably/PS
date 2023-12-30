import sys

str = sys.stdin.readline().rstrip()
bomb = sys.stdin.readline().rstrip()
n = len(bomb)

stack = []

for i in range(len(str)):
    stack.append(str[i])

    # 스택의 뒤 n개의 글자
    stack_n_word = ''.join(stack[-n:])
    if stack_n_word == bomb:
        # 폭발시키기
        for _ in range(n):
            stack.pop()

if stack:
    print(''.join(stack))
else:
    print('FRULA')
    
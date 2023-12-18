import sys

str = sys.stdin.readline()
stack = []
temp = 1 # 임시변수
answer = 0 # 답

for i in range(len(str)):
    if str[i] == '(':
        temp *= 2
        stack.append('(')

    elif str[i] == '[':
        temp *= 3
        stack.append('[')

    elif str[i] == ')':
        # stack이 비어있거나 마지막으로 남아있는 스택이 ( 가 아니라면
        if not stack or stack[-1] != '(':
            answer = 0
            break
        # 바로 이전꺼가 ( 이면 답에 추가
        elif str[i-1] == '(':
            answer += temp
        # 공통적으로 temp를 다시 2로 나누어주고 기존의 ( 하나 제거
        temp //= 2
        stack.pop()

    elif str[i] == ']':
        # stack이 비어있거나 마지막으로 남아있는 스택이 [ 가 아니라면
        if not stack or stack[-1] != '[':
            answer = 0
            break

        elif str[i-1] == '[':
            answer += temp

        temp //= 3
        stack.pop()


# stack에 남아있는게 있다면
if stack:
    print(0)
else:
    print(answer)

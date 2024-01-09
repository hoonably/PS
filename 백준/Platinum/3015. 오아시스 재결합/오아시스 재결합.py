import sys

N = int(sys.stdin.readline())
H = [0]*N
for i in range(N):
    H[i] = int(sys.stdin.readline())
stack = []

ans = 0

for i in range(N):
    # 스택 내림차순 유지
    while stack and stack[-1][0] < H[i]:
        ans += stack.pop()[1]

    if not stack:
        stack.append([H[i], 1])
    else:
        # 같은 경우 스택이 쌓일때 모두 보임
        if stack[-1][0] == H[i]:
            ans += stack[-1][1]
            stack[-1][1] += 1
            if len(stack) > 1:
                ans += 1
        else:
            stack.append([H[i], 1])
            ans += 1
print(ans)
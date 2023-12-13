import sys

N = int(sys.stdin.readline())
tower = list(map(int, sys.stdin.readline().split()))
arr = [0] * N
stack = []
for i in range(N):
    while stack:
        # 스택 마지막꺼의 x값 (영향이 갈 수 있는 최근 타워부터)
        if tower[stack[-1][0]] < tower[i]:
            stack.pop()
        else:

            arr[i] = stack[-1][0] + 1
            break

    stack.append((i, tower[i]))
print(*arr)


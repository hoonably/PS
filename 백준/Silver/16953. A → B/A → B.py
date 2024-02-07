import sys
from collections import deque


def bfs(A, B):
    queue = deque()
    queue.append([A, 0])
    depth = 0

    while queue:
        cur_node, cur_depth = queue.popleft()

        if cur_node > B:
            continue

        elif cur_node == B:
            return cur_depth + 1

        # 2 곱하기
        queue.append([cur_node*2, cur_depth + 1])

        # 1 추가하기
        queue.append([cur_node*10+1, cur_depth + 1])

        depth += 1

    return -1

A, B = map(int, sys.stdin.readline().split())
print(bfs(A, B))

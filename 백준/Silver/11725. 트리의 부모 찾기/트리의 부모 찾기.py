import sys
from collections import deque


def bfs(start_node, graph):
    queue = deque([start_node])

    while queue:
        curr_node = queue.popleft()

        for next_node in graph[curr_node]:
            if not visited[next_node]:
                parent[next_node] = curr_node
                visited[next_node] = True
                queue.append(next_node)

N = int(sys.stdin.readline())
visited = [False]*(N+1)
parent = [0]*(N+1)
tree = [[] for _ in range(N+1)]

for _ in range(N-1):
    s, e = map(int, sys.stdin.readline().split())
    tree[s].append(e)
    tree[e].append(s)

bfs(1, tree)

for i in range(2, N+1):
    print(parent[i])

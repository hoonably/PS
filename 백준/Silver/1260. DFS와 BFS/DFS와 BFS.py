import sys
from collections import deque

def dfs(curr_node, graph, visited):
    visited.add(curr_node)
    print(curr_node, end=' ')

    for next_node in graph[curr_node]:
        if next_node not in visited:
            dfs(next_node, graph, visited)

    return visited

def bfs(start_node, graph):
    queue = deque([start_node])
    visited = {start_node}

    while queue:
        curr_node = queue.popleft()
        print(curr_node, end=' ')
        for next_node in graph[curr_node]:
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)

    return visited

# 딕셔너리 그래프
graph = {}

N, M, V = map(int, sys.stdin.readline().split())
for _ in range(M):
    start, end = map(int, sys.stdin.readline().split())
    if start in graph:
        graph[start].append(end)
    else:
        graph[start]=[end]
    if end in graph:
        graph[end].append(start)
    else:
        graph[end]=[start]

for i in graph:
    graph[i].sort()

# 시작지점이랑 연결된 것이 없을 때
if V not in graph:
    graph[V] = []

# dfs위해 visited 생성
visited = set()
dfs(V, graph, visited)
print()
bfs(V, graph)


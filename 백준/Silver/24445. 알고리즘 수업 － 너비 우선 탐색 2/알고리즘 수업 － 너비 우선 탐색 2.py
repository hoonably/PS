import sys
from collections import deque

def bfs(start_node, graph):
    queue = deque([start_node])
    visited = {start_node}
    seq = 1 # 몇번째로 방문하는
    while queue:
        curr_node = queue.popleft()
        ans[curr_node -1] = seq
        seq += 1
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
    graph[i].sort(reverse=True)

# 시작지점이랑 연결된 것이 없을 때
if V not in graph:
    graph[V] = []

ans = [0]*N
bfs(V, graph)
for i in ans:
    print(i)

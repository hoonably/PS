import sys
sys.setrecursionlimit(10**6)

def dfs(curr_node, graph, visited):
    global seq

    visited.add(curr_node)

    ans[curr_node - 1] = seq
    seq += 1

    for next_node in graph[curr_node]:
        if next_node not in visited:
            dfs(next_node, graph, visited)

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

# dfs위해 visited 생성
visited = set()
ans = [0]*N
seq = 1
dfs(V, graph, visited)

for i in ans:
    print(i)

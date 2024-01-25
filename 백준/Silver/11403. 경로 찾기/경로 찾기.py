import sys

from collections import deque

# 끝까지 완전탐색했을 때 visited return
def bfs(start_node, graph):
    queue = deque([start_node])
    visited = [0]*N

    while queue:
        curr_node = queue.popleft()

        for next_node in graph[curr_node]:
            if visited[next_node] == 0:
                visited[next_node] ^= 1
                queue.append(next_node)
    return visited

N = int(input())

graph = {}  # 딕셔너리 생성

for i in range(N):
    graph[i] = []
    get_arr = list(map(int,sys.stdin.readline().split()))
    for j in range(N):
        if get_arr[j] == 1:
            graph[i].append(j)

for i in range(N):
    print(*bfs(i, graph))

import sys
from collections import deque

def bfs(start_node, graph):
    queue = deque([start_node])
    visited = {start_node}

    while queue:
        curr_node = queue.popleft()

        for next_node in graph[curr_node]:
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)
    return visited

# 딕셔너리 그래프
n = int(input())
dic = {}
m = int(input())

for i in range(m):
    key, value = map(int, sys.stdin.readline().split())
    if key not in dic:
        dic[key] = {value}
    else:
        dic[key].add(value)
    if value not in dic:
        dic[value] = {key}
    else:
        dic[value].add(key)

# 1과 연결되어있는게 하나도 없을 경우
if 1 not in dic:
    print(0)
else:
    print(len(bfs(1, dic)) - 1)  # 1 자신 제외

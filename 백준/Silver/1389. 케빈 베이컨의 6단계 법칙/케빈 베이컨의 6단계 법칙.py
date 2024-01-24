import sys

from collections import deque

def Kevin_bacon(start_node, end_node):
    queue = deque([start_node])
    visited = {start_node}
    dist = {start_node: 0}  # 거리 딕셔너리 생성

    while queue:
        curr_node = queue.popleft()

        if curr_node == end_node: # 탐색 종료시 최단 거리 리턴
            return dist[curr_node]

        for next_node in graph[curr_node]:

            if next_node not in visited:  # visit check
                visited.add(next_node)
                queue.append(next_node)

                # print(next_node) # 노드 방문 순서
                dist[next_node] = dist[curr_node] + 1  # 최단거리 기록

    return -1  # 큐가 비었는데 도달 못했을 경우

N, M = map(int,sys.stdin.readline().split())
graph = {}  # 딕셔너리
for i in range(1,N+1):
    graph[i] = set()

for _ in range(M):
    key, value = map(int, sys.stdin.readline().split())
    graph[key].add(value)
    graph[value].add(key)

best = 5000
ans = 0

for i in range(1,N+1):
    temp = 0
    for j in range(1,N+1):
        if i==j:
            continue
        temp += Kevin_bacon(i,j)
    # print(temp)  # 케빈 베이컨 수
    if temp < best:
        ans = i
        best = temp

print(ans)
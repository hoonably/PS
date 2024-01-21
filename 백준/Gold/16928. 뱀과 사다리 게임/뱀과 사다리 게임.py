# 현재 노드를 기준으로 이동할 수 있는 모든 노드 탐색
import sys
from collections import deque

def bfs(start_node, end_node, graph):
    queue = deque([start_node])
    visited = {start_node}
    dist = {start_node: 0}  # 거리 딕셔너리 생성

    while queue:
        curr_node = queue.popleft()

        if curr_node == end_node:  # 탐색 종료시 최단 거리 리턴
            return dist[curr_node]

        for i in range(1, 7):
            next_node = curr_node + i

            if next_node in graph:  # 뱀이나 사다리를 만났다면 바로 바꿔주기
                next_node = graph[next_node]

            if next_node not in visited:  # visit check
                visited.add(next_node)
                queue.append(next_node)

                # print(next_node) # 노드 방문 순서
                dist[next_node] = dist[curr_node] + 1  # 최단거리 기록

    return -1  # 큐가 비었는데 도달 못했을 경우

# 딕셔너리 그래프
dic = {}

N, M = map(int, sys.stdin.readline().split())
for _ in range(N+M):
    start, end = map(int, sys.stdin.readline().split())
    dic[start] = end

print(bfs(1, 100, dic))

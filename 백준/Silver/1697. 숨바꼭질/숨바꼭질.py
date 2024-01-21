# 현재 노드를 기준으로 이동할 수 있는 모든 노드 탐색

from collections import deque

def bfs(start_node, end_node):
    queue = deque([start_node])
    visited = {start_node}
    dist = {start_node: 0}  # 거리 딕셔너리 생성

    while queue:
        curr_node = queue.popleft()

        if curr_node == end_node: # 탐색 종료시 최단 거리 리턴
            return dist[curr_node]

        for i in [-1, 1, 2]:
            if i == 2:
                next_node = curr_node * 2
            else:
                next_node = curr_node + i

            if 0 <= next_node <= 100000:  # 배열 범위 내에 있는지
                if next_node not in visited:  # visit check
                    visited.add(next_node)
                    queue.append(next_node)

                    # print(next_node) # 노드 방문 순서
                    dist[next_node] = dist[curr_node] + 1  # 최단거리 기록

    return -1  # 큐가 비었는데 도달 못했을 경우


N, K = map(int, input().split())
print(bfs(N, K))

# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.


import sys
import heapq

def dijkstra(start):
    # distance[i] : i노드까지 가는 최단거리
    distance = [INF] * (V + 1)  # V: 노드의 개수
    heap = []

    distance[start] = 0
    heapq.heappush(heap,(0, start))  # 순서 중요 (힙큐이기 때문에)

    while heap:
        now_dist, now_node = heapq.heappop(heap)

        # 현재 테이블보다 가중치가 큰 튜플이면 무시
        if now_dist > distance[now_node]:
            continue

        for next_node, dist in graph[now_node]:
            next_dist = dist + now_dist
            if next_dist < distance[next_node]:  # 유망하면
                distance[next_node] = next_dist
                heapq.heappush(heap,(next_dist, next_node))
    return distance

INF = sys.maxsize
V, E, x = map(int, sys.stdin.readline().split())  # V: 노드 개수, E: 간선 개수

# 간선 그래프
graph = [[] for _ in range(V + 1)]

for _ in range(E):  # 간선 받기
    u, v, w = map(int, sys.stdin.readline().split())
    # (목적지 노드, 가중치) 형태로 저장
    graph[u].append((v, w))

result = 0
for i in range(1, V + 1):
    go = dijkstra(i)
    back = dijkstra(x)
    result = max(result, go[x] + back[i])

print(result)

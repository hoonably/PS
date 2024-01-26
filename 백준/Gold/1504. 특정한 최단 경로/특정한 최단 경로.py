import sys
import heapq

def dijkstra(start):
    dist = [INF] * (N + 1)
    dist[start] = 0
    heap = []
    heapq.heappush(heap,(0, start))  # 순서 중요 (힙큐이기 때문에)

    #힙에 원소가 없을 때 까지 반복.
    while heap:
        now_dist, now_node = heapq.heappop(heap)

        # 현재 테이블보다 가중치가 큰 튜플이면 무시
        if dist[now_node] < now_dist:
            continue

        for w, next_node in graph[now_node]:
            next_dist = w + now_dist
            if next_dist < dist[next_node]:  # 유망하면
                dist[next_node] = next_dist
                heapq.heappush(heap,(next_dist, next_node))
    return dist

INF = sys.maxsize
N, E = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]

for _ in range(E):
    a, b, c = map(int, sys.stdin.readline().split())
    # (가중치, 목적지 노드) 형태로 저장
    graph[a].append((c, b))
    graph[b].append((c, a))

v1, v2 = map(int, sys.stdin.readline().split())

# 출발점이 각각 1, v1, v2일 때의 최단 거리 배열
original_distance = dijkstra(1)
v1_distance = dijkstra(v1)
v2_distance = dijkstra(v2)

# v1 -> v2 -> v 로 가는 경우
v1_path = original_distance[v1] + v1_distance[v2] + v2_distance[-1]
# v2 -> v1 -> v 로 가는 경우
v2_path = original_distance[v2] + v2_distance[v1] + v1_distance[-1]

result = min(v1_path, v2_path)
print(result if result < INF else -1)
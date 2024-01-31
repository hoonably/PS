import sys
import heapq

def dijkstra(start):
    # distance[i] : i노드까지 가는 최단거리
    distance = [INF] * (V + 1)
    heap = []

    distance[start] = 0
    heapq.heappush(heap,(0, start))  # 순서 중요 (힙큐이기 때문에)

    #힙에 원소가 없을 때 까지 반복.
    while heap:
        now_dist, now_node = heapq.heappop(heap)

        # 현재 테이블보다 가중치가 큰 튜플이면 무시
        if distance[now_node] < now_dist:
            continue

        for next_node, dist in graph[now_node]:
            next_dist = dist + now_dist
            if next_dist < distance[next_node]:  # 유망하면
                distance[next_node] = next_dist
                heapq.heappush(heap,(next_dist, next_node))

    return distance

INF = sys.maxsize
V = int(sys.stdin.readline())
E = int(sys.stdin.readline())

graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    # (목적지 노드, 가중치) 형태로 저장
    graph[u].append((v, w))

start_node, end_node = map(int, sys.stdin.readline().split())

# K에서 출발할때 모든 곳의 최단 경로
dp1 = dijkstra(start_node)

print(dp1[end_node])

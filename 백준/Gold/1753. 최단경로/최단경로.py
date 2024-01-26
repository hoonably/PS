import sys
import heapq

def dijkstra(start):
    dp[start] = 0
    heapq.heappush(heap,(0, start))  # 순서 중요 (힙큐이기 때문에)

    #힙에 원소가 없을 때 까지 반복.
    while heap:
        now_dist, now_node = heapq.heappop(heap)

        # 현재 테이블보다 가중치가 큰 튜플이면 무시
        if dp[now_node] < now_dist:
            continue

        for w, next_node in graph[now_node]:
            next_dist = w + now_dist
            if next_dist < dp[next_node]:  # 유망하면
                dp[next_node] = next_dist
                heapq.heappush(heap,(next_dist, next_node))

INF = sys.maxsize
V, E = map(int, sys.stdin.readline().split())
#시작점 K
K = int(sys.stdin.readline())
#가중치 테이블 dp
dp = [INF]*(V+1)
heap = []
graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    #(가중치, 목적지 노드) 형태로 저장
    graph[u].append((w, v))

dijkstra(K)
for i in range(1,V+1):
    print("INF" if dp[i] == INF else dp[i])

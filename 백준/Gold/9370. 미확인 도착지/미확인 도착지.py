import sys
import heapq

def dijkstra(start):
    # dp[i][j] : i노드에서 j노드까지 가는 최단거리
    dp = [INF] * (n + 1)
    heap = []

    dp[start] = 0
    heapq.heappush(heap,(0, start))  # 순서 중요 (힙큐이기 때문에)

    #힙에 원소가 없을 때 까지 반복.
    while heap:
        now_dist, now_node = heapq.heappop(heap)

        # 현재 테이블보다 가중치가 큰 튜플이면 무시
        if dp[now_node] < now_dist:
            continue

        for next_node, dist in graph[now_node]:
            next_dist = dist + now_dist
            if next_dist < dp[next_node]:  # 유망하면
                dp[next_node] = next_dist
                heapq.heappush(heap,(next_dist, next_node))
    return dp


INF = sys.maxsize

T = int(sys.stdin.readline())
for _ in range(T):

    n, m, t = map(int, sys.stdin.readline().split())
    # s = 출발지, g, h = 무조건 지나는 경로
    s, g, h = map(int, sys.stdin.readline().split())

    graph = [[] for _ in range(n + 1)]

    # 다익스트라 외의 그냥 경로의 가중치를 저장해주는 그래프
    temp_graph = [[0]*(n+1) for _ in range(n + 1)]

    # 최단거리 테이블
    dp = [INF] * (n + 1)
    heap = []

    for _ in range(m):
        a, b, d = map(int, sys.stdin.readline().split())
        graph[a].append((b, d))
        graph[b].append((a, d))
        temp_graph[a][b] = d
        temp_graph[b][a] = d

    goal = [0]*t
    for i in range(t):
        goal[i] = int(sys.stdin.readline())

    start_s = dijkstra(s)  # s에서 출발
    start_g = dijkstra(g)  # g에서 출발
    start_h = dijkstra(h)  # h에서 출발

    goal.sort()
    for i in goal:
        # s -> g -> h -> i (목적지)인경우
        if start_s[i] == start_s[g] + temp_graph[g][h] + start_h[i]:
            print(i, end=' ')
        # s -> h -> g -> i (목적지)인경우
        elif start_s[i] == start_s[h] + temp_graph[h][g] + start_g[i]:
            print(i, end=' ')
    print()
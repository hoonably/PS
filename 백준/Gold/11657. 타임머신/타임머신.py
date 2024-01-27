# 벨만 포드 알고리즘
# 음수 간선이 있을 때 사용 (다익스트라 사용시 무한루프 발생)
# 시간복잡도 : O(VE)
# V번 반복에 대해서 해당 정점과 연결되어 있는 모든 간선(E)을 탐색해주기 때문에
# 다익스트라보다 시간 복잡도가 느리니 음수 간선있을때만 사용한다.

# 백준 11657 타임머신 문제의 풀이와 동일하다.

import sys

def bellman_ford(start):
    distance = [INF] * (v + 1)
    distance[start] = 0

    # 전체 v - 1번의 라운드(round)를 반복
    for i in range(v):
        for j in range(e):
            cur_node, next_node, cost = graph[j]
            # 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if distance[cur_node] != INF and distance[next_node] > distance[cur_node] + cost:
                distance[next_node] = distance[cur_node] + cost

                # v(노드개수)만큼 반복했을때도 갱신된다면
                if i == v - 1:
                    return True, []  # 음수 순환 존재

    return False, distance  # 음수 순환 없고, 최단거리 리스트 반환

INF = sys.maxsize

# v: 노드 개수, e: 간선 개수
v, e = map(int, sys.stdin.readline().split())

graph = []

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph.append((a, b, c))  # a -> b 의 비용이 c

negative_cycle_from_1, distacne_from_1 = bellman_ford(1)

if negative_cycle_from_1:  # 음수 순환 존재
    print(-1)
else:
    for i in range(2, v + 1):
        if distacne_from_1[i] == INF:  # 도달 못함
            print(-1)
        else:
            print(distacne_from_1[i])  # 도달

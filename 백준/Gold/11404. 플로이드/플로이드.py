'''
< 플로이드 워셜 알고리즘 >
모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우
다익스트라에서 최단 거리 테이블에서 거리가 가장 짧은 노드를 탐색해야 했던 과정을 생략할 수 있다
시간복잡도 : O(N^3)
Dab = min(Dab, Dak + Dkb)
'''
import sys

input = sys.stdin.readline
INF = int(1e9)
n = int(input())
m = int(input())
graph = [[INF] * (n + 1) for _ in range(n + 1)]

for x in range(1, n + 1):
    graph[x][x] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    # 시작노드와 끝 노드가 같더라도 간선이 다를 경우 고려
    # ex) 1->3 비용이 3인 경로와 5인 경로가 둘다 존재
    graph[a][b] = min(graph[a][b], c)

for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print(0, end=" ")
        else:
            print(graph[a][b], end=" ")
    print()
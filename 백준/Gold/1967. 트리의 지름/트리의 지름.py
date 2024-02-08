import sys
from collections import deque

N = int(sys.stdin.readline())
visited = [False]*(N+1)
tree = [[] for _ in range(N+1)]

for _ in range(N-1):
    par, son, dist = map(int, sys.stdin.readline().split())
    tree[par].append((son, dist))
    tree[son].append((par, dist))

# start_node로부터 가장 먼 노드와 거리를 뽑아내는 함수
def bfs(start_node):
    queue = deque()
    queue.append((start_node, 0))
    visited = [False] * (N + 1)
    visited[start_node] = True
    diameter_of_tree = 0  # start node 로부터 가장 먼 거리
    diameter_point = 0  # start node 로부터 가장 먼 노드

    while queue:
        now_node, now_dist = queue.popleft()
        for next_node, next_dist in tree[now_node]:
            if not visited[next_node]:
                next_dist += now_dist
                queue.append((next_node, next_dist))
                visited[next_node] = True

                # 가장 먼 노드와 그 길이 갱신
                if diameter_of_tree < next_dist:
                    diameter_point = next_node
                    diameter_of_tree = next_dist

    return diameter_of_tree, diameter_point

# 트리의 지름 : 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
# 트리의 지름을 구하는 방법
# 임의의 점 (1) 부터 가장 먼 거리의 노드 (point) 를 구한다.
# 그 후 그 point에서 가장 먼 거리로 한번 더 탐색을 하면 그게 최대인 지름이다.

point = bfs(1)[1]
print(bfs(point)[0])

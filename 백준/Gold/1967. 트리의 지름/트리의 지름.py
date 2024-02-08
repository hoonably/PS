import sys
sys.setrecursionlimit(10**5)

# 이번엔 dfs로 구현
def dfs(node, cost):
    for next_node, next_dist in tree[node]:
        next_dist += cost
        if visited[next_node] == -1:
            visited[next_node] = next_dist  # 방문 표시를 거리로
            dfs(next_node, next_dist)
    return

N = int(sys.stdin.readline())
tree = [[] for _ in range(N+1)]

for _ in range(N-1):
    par, son, dist = map(int, sys.stdin.readline().split())
    tree[par].append((son, dist))
    tree[son].append((par, dist))

# 트리의 지름 : 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
# 트리의 지름을 구하는 방법
# 임의의 점 (1) 부터 가장 먼 거리의 노드 (point) 를 구한다.
# 그 후 그 point에서 가장 먼 거리로 한번 더 탐색을 하면 그게 최대인 지름이다.

visited = [-1]*(N+1)
visited[1] = True
dfs(1, 0)
best_idx, best_dist = 0, 0
for i in range(2, N+1):
    if visited[i] > best_dist:
        best_idx = i
        best_dist = visited[i]

# 다시 한번 더
visited = [-1]*(N+1)
visited[best_idx] = 0
dfs(best_idx, 0)

print(max(visited))

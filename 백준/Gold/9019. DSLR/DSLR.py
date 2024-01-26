# 9019 DSLR
import sys
from collections import deque

def DSLR(num, command):
    if command==0:  # D
        return num*2%10000, 'D'

    if command==1:  # S
        if num==0:
            return 9999, 'S'
        return num - 1, 'S'

    if command==2:  # L
        num = num % 1000 * 10 + num//1000
        return num, 'L'

    if command==3:  # R
        temp = num % 10  # 천의자리로 올라가는것
        temp2 = num // 10 # 나머지
        num = temp*1000 + temp2
        return num, 'R'

def bfs(start_node, end_node):
    queue = deque([start_node])
    visited = [0]*10001  # 방문 집합 생성
    visited[start_node] ^= 1
    path = ['']*10001  # 최단 경로

    while queue:
        curr_node = queue.popleft()

        if curr_node == end_node:  # 탐색 종료시 최단 경로와 최단 거리 리턴
            return path[curr_node]

        for i in range(4):
            next_node, command = DSLR(curr_node, i)
            if visited[next_node] == 0:
                visited[next_node] ^= 1
                queue.append(next_node)
                # 다음 노드까지의 경로: [현재경로] + 다음 노드
                path[next_node] = path[curr_node] + command

T = int(input())
for _ in range(T):
    A, B = map(int, sys.stdin.readline().split())
    print(bfs(A, B))

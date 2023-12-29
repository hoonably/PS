import sys

N, M = map(int, sys.stdin.readline().split())

nums = list(map(int, sys.stdin.readline().split()))
nums.sort()

arr = []

def backtracking(n):
    # 갯수 완성했으면 출력
    if n == M:
        print(*arr)
        return

    #모든 자식 노드에 대해
    for i in range(N):

        # 뒤에가 더 작거나 같은거 방지
        if arr and nums[i] <= arr[-1]:
            continue

        arr.append(nums[i])
        # 유망하면 자식노드로 이동
        backtracking(n+1)
        # 백트래킹 다 끝나면 부모노드로 이동
        arr.pop()

backtracking(0)
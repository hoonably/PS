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

    # 중복수열 방지
    temp = 0

    #모든 자식 노드에 대해
    for i in range(N):

        if  temp != nums[i]:
            # 유망하면 자식노드로 이동
            arr.append(nums[i])

            # 마지막으로 넣은 것 저장
            temp = nums[i]
            backtracking(n+1)

            # 백트래킹 다 끝나면 부모노드로 이동
            arr.pop()

backtracking(0)

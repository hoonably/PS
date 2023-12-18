import sys

N, M = map(int, sys.stdin.readline().split())
trees = list(map(int,sys.stdin.readline().split()))

start, end = 1, max(trees)

# start가 end보다 커질때까지 반복
while start<=end:
    mid = (start+end)//2
    tree_sum = 0
    for tree in trees:
        if tree>mid:
            tree_sum+=tree-mid
    # 자른 나무의 합이 생각한거보다 크거나 같으면
    # 같은것도 넣어주는 이유 : start가 end보다 커져야 끝나고 end값을 출력할 것이라서
    #                    start=end일때 start를 올려줘야 나중에 출력값이 정상적으로 나옴
    if tree_sum>=M:
        start = mid+1
    else:
        end = mid-1


print(end)
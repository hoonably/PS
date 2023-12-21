N, M = map(int,input().split())
s_list = []

# 조합 Combination nCr 이다.

# 이전 문제와 비슷하지만 시작구간을 정해서
# 무조건 리스트를 정렬된 순서로만 만들도록 한다.
def dfs(start):
    if len(s_list)==M:
        print(*s_list)
        return

    for i in range(start,N+1):
        s_list.append(i)
        dfs(i+1)
        s_list.pop()

# 시작 : 1
dfs(1)
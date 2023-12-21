N, M = map(int,input().split())
s_list = []

# 중복을 포함한 순열  nπr

def permutation2():
    if len(s_list)==M:
        print(*s_list)
        return

    for i in range(1,N+1):
        s_list.append(i)
        permutation2()
        s_list.pop()

permutation2()
# 절대값 식 합하는 함수
# |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
def abs_sum(list):
    sum = 0
    for i in range(1,len(list)):
        sum += abs(list[i-1]-list[i])
    return sum

def bfs(list):
    global answer
    if len(list) == N and abs_sum(list)>answer:
        answer = abs_sum(list)
        return
    for i in range(N):
        # 앞에서 사용하지 않았다면
        if not visited[i]:
            visited[i] = True # 사용으로 바꿈
            list.append(A[i]) # 넣기
            bfs(list) # 재귀함수
            # 재귀함수 끝내면 다시 이전의 부모 노드로 이동
            # 넣었던거 지워줌
            visited[i] = False
            list.pop()

N = int(input())
A = list(map(int, input().split()))
visited = [False]*N

answer = 0
bfs([])
print(answer)


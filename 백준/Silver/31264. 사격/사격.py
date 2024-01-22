import sys

N, M, A = map(int, sys.stdin.readline().split())
S = list(map(int, sys.stdin.readline().split()))
S.sort()

# 최소 시작 지점
# go = A
# for _ in range(M):
#     go //= 2

go = S[0]

def binary_search(target, data):
    start = 0 			# 맨 처음 위치
    end = len(data) - 1 	# 맨 마지막 위치

    while start <= end:
        mid = (start + end) // 2  # 중간값
        if data[mid] > target:  # target이 작으면 왼쪽을 더 탐색
            end = mid - 1
        else:                    # target이 크면 오른쪽을 더 탐색
            start = mid + 1
    return end


def dfs(score):
    start_score = score
    chance = M
    temp_S = S.copy()
    # print("now_score", score, "remain: ", temp_S, end=' ')
    while chance>0:
        if score < temp_S[0]:
            # print("Can't shoot")
            break
        bs = binary_search(score, temp_S)
        # print("shoot : ", temp_S[bs])
        score += temp_S[bs]
        # print("now_score", score, "표적: ", temp_S, end=' ')
        chance -= 1

    # print("\ntotal : ", score - start_score, "\n")

    if score - start_score >= A:
        print(go)

        return True
    else:
        return False


while True:
    if dfs(go):
        break
    go+=1

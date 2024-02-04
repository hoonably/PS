import sys

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

N, M, A = map(int, sys.stdin.readline().split())
S = list(map(int, sys.stdin.readline().split()))
S.sort()

# print(S)

# 최소 시작 지점
start_score = A
for _ in range(M):
    start_score //= 2
start_score = max(start_score, S[0])

while True:
    score = start_score
    chance = M
    while chance > 0:
        bs = binary_search(score, S)
        # print("now_score", score, "shoot : ", S[bs])
        score += S[bs]
        chance -= 1

    # print("\ntotal : ", score - start_score, "\n")

    if score - start_score >= A:
        print(start_score)
        break
    else:
        start_score += 1

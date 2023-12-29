N, K = int(input()), int(input())
start, end = 1, K
answer=0

# 10 * 10에서 20보다 작거나 같은 수를 생각해보자.
# 이는 반대로 생각해보면 20을 행으로 나눈 몫이다.
#
# 20//1: 20이지만 열의 개수를 초과할 수 없으니 10개
# 20//2: 10개
# 20//3: 6개


while start <= end:
    mid = (start + end) // 2  # 중간값

    temp = 0
    # 1부터 N행까지 나눠본다.
    for i in range(1, N+1):
        # 20을 행으로 나눈 몫 (최대는 N)
        temp += min(mid//i, N)

    # 이분탐색

    # 갯수가 K보다 크거나 같으면
    if temp >= K:
        answer = mid
        end = mid-1

    # 갯수가 K보다 작으면
    else:
        start = mid+1

print(answer)
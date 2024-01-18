import sys
input = sys.stdin.readline

# 사용한 추의 개수, num개의 추를 사용하여 만든 구슬의 무게
def cal(num, weight):
    # 사용할 수 있는 추의 개수를 넘어가면 종료
    if num > N:
        return

    # 1. num번째까지 추로 weight 무게를 만들 수 있음이 이미 기록되어있으면 종료
    if d[num][weight]:
        return
    # 2. num번째까지 추로 weight 무게를 만들 수 있음을 체크
    d[num][weight] = True

    # 3가지 경우 수행
    cal(num + 1, weight + weights[num - 1])  # 추의 무게를 더함
    cal(num + 1, abs(weight - weights[num - 1]))  # 추의 무게를 뺌
    cal(num + 1, weight)  # 추를 사용하지 않음




# 사용할 추들
N = int(input())
weights = list(map(int, input().split()))

# 확인할 구슬들
_ = input()
checks = list(map(int, input().split()))

# d[i][j]: i번째까지 추를 사용했을 때 j무게를 만들 수 있는지 여부
d = [[False] * 15001 for _ in range(31)]

cal(0,0)

for check in checks:
    # 만들 수 있는 구슬의 무게는 30*500이 최대임
    if check > 15000:
        print("N", end=" ")
    # N번째까지 추로 check를 만들 수 있는지
    elif d[N][check]:
        print("Y", end=" ")
    else:
        print("N", end=" ")
        
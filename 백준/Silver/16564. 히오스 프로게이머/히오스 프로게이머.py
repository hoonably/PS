import sys

N, K = map(int,sys.stdin.readline().split())
ch_level = []
for _ in range(N):
    ch_level.append(int(sys.stdin.readline()))

# 목표 레벨(최소 레벨)로 이분탐색
# 목표 레벨을 mid로 잡았을 때
# 1. 레벨업량이 K보다 적다면 목표 레벨을 늘려야하니 mid~end 부분 탐색
# 2. 레벨업량이 K보다 많다면 목표 레벨을 줄여야하니 start~mid 부분 탐색
# 두번째 경우에서는 result를 저장하면 절대 안됨.


start = min(ch_level)
end = start+K

while start<=end:
    # 목표 레벨
    mid = (start+end)//2
    # 필요한 레벨을 위해 레벨업을 얼마나 했는가 레벨업 량 세팅
    count = 0
    for level in ch_level:
        if level < mid: # 각 캐릭터별 레벨이 필요 레벨보다 낮다면
            count += mid - level # 레벨업 한 만큼 기록

    if count <= K:
        result = mid
        start = mid + 1
    else:
        end = mid - 1
print(result)
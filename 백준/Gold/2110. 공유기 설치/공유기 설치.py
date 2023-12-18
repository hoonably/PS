import sys

N, C = map(int,sys.stdin.readline().split())
houses = []
for _ in range(N):
    houses.append(int(sys.stdin.readline()))

houses.sort()

# 설치 간격으로 이분탐색
# 설치 간격을 mid로 잡고 설치해봤더니
# 공유기의 수가 C보다 많다면 간격을 늘려야하니 mid~end 부분 탐색
# 공유기의 수가 C보다 부족하다면 간격을 줄여야하니 start~mid 부분 탐색

start, end = 1, houses[-1]-houses[0]
while start<=end:
    mid = (start+end)//2
    # 마지막으로 설치한 공유기 위치
    last = houses[0]    # 무조건 양 끝 집은 설치가 된다고 놓고 풀어도 무방하다.

    count = 1 # 공유기의 수 (첫번째꺼 이미 놨으니 1부터 시작)
    for i in range(1,len(houses)):
        if houses[i]-last>=mid:
            count+=1
            last = houses[i]
    if count>=C:
        start = mid+1
    else:
        end = mid-1
print(end)

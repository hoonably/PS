import sys

K, N = map(int,sys.stdin.readline().split())

lan_list = []
for _ in range(K):
    lan_list.append(int(sys.stdin.readline()))

# 시간 초과가 날 수 있기 때문에 이분탐색을 사용한다.
start = 1
end = max(lan_list)

while start <= end:
    mid = (start+end) // 2
    lan_num = 0
    for lan in lan_list:
        lan_num += lan // mid
    if lan_num >= N:
        start = mid+1 # 반으로 쪼개서 뒤부분만 볼거임
    else:
        end = mid-1 # 반으로 쪼개서 앞부분만 볼거임

print(end)


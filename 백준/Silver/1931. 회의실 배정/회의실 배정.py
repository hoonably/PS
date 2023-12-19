import sys

N = int(sys.stdin.readline())
time = []
for i in range(N):
    start, end = map(int, sys.stdin.readline().split())
    time.append([start, end])
# 끝나는 시간 기준으로 2차원 배열 정렬
time.sort(key=lambda x: (x[1], x[0]))

end_point = 0
answer = 0

# 2차원 배열 for문 변수 두개
for s,e in time:
    # 시작지점이 마지막 end_point보다 크거나 같을때 회의 가능
    if end_point<=s:
        answer+=1
        end_point = e
print(answer)
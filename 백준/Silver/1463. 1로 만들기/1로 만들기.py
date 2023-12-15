import sys

N = int(input())

arr=[0] * (N+1)
for i in range(2, N+1):
    # DP 다이나믹 프로그래밍
    # 모든 가능성을 두고 그 중 최소값을 찾기
    # 3가지를 동시에 진행시키고
    # 그 중 최소값을 남기고 푸는 방법

    # 2나 3으로 안나눠질 수 있으므로
    # 나중 비교를 위해 일단 최대값으로 초기화
    div2, div3 = sys.maxsize, sys.maxsize

    # 1을 빼는 경우
    minus1 = arr[i-1]+1
    # 2를 나누는 경우
    if i%2==0:
        div2 = arr[i//2]+1
    # 3을 나누는 경우
    if i%3==0:
        div3 = arr[i//3]+1

    # 3가지 경우 중 최소값 arr에 대입
    arr[i] = min(minus1, div2, div3)

print(arr[N])
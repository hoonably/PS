n, k = map(int, input().split())

# 나머지 리스트
mod = [0] * k
x = 10**len(str(n))
cnt = 1
res = n
while True:
    remain = n % k

    if remain == 0:  # 나누어 떨어지면
        print(cnt)
        break

    if mod[remain] != 0:  # 이미 기록이 되어있다면 주기로 계속 반복할 예정이니
        print(-1)
        break

    cnt += 1
    n = remain * x + res
    mod[remain] = 1

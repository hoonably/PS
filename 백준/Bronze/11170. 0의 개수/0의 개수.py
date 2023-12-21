T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    answer = 0
    for i in range(N,M+1):
        i = str(i)
        # 문자열에서 포함된게 몇개인지 셀때는 count 함수 이용
        answer += i.count('0')
    print(answer)
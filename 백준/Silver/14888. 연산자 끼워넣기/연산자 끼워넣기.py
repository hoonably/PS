def solve(n):
    global answer
    if n==0:
        answer = num[0]
        solve(1)
        return
    if n==N:
        ans_list.append(answer)
        return
    for i in range(4):
        if operator[i]>0:

            temp = answer # temp에 이전 값 저장
            operator[i] -= 1

            # 연산 실행
            if i==0:
                answer += num[n]
            elif i==1:
                answer -= num[n]
            elif i == 2:
                answer *= num[n]
            elif i == 3:
                if answer < 0:
                    answer = -answer
                    answer //= num[n]
                    answer = -answer
                else:
                    answer //= num[n]

            # 다음단계 실행
            solve(n+1)

            #다시 넣기 이전으로 복구
            answer = temp
            operator[i] += 1


import sys

N = int(sys.stdin.readline())
# N 개의 수 리스트
num = list(map(int, sys.stdin.readline().split()))
# 각 연산자의 개수 [+,-,×,÷]
operator = list(map(int, sys.stdin.readline().split()))

ans_list = []

solve(0)

print(int(max(ans_list)))
print(int(min(ans_list)))
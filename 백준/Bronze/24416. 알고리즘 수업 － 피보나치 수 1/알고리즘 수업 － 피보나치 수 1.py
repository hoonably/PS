answer=0
# 재귀의 실행 횟수 : 피보나치 함수 결과값과 같다.
# def fib1(n):
#     global answer
#     if  n==1 or n==2:
#         answer+=1
#         return 1
#     return fib1(n-1) + fib1(n-2)

# 동적
f = [0]*41
def fib2(n):
    global answer
    f[1] = 1
    f[2] = 1
    for i in range(3,n+1):
        answer+=1
        f[i]=f[i-1]+f[i-2]
    return f[n]

n = int(input())
print(fib2(n), answer)
def factorial(n):
    answer = 1
    for i in range(1, n+1):
        answer *= i
    return answer

N = int(input())
fac = factorial(N)
fac = str(fac)

answer = 0
for i in reversed(fac):
    if i!='0':
        break
    answer+=1
print(answer)
import sys

N = int(input())
numbers = list(map(int, sys.stdin.readline().split()))

answer = 0 # 소수 개수
for i in numbers:
    #1은 소수가 아니므로 건너 뜀
    if i==1:
        continue

    sosu = True
    for j in range(2,i//2+1): # 2부터 n/2 까지 확인
        if i%j==0:
            sosu = False
            break
    if sosu:
        answer+=1
print(answer)
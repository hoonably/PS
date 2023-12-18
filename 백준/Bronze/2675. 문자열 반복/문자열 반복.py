T = int(input())
for _ in range(T):
    repeat, str = input().split()
    for i in str:
        #파이썬의 print는 자동 줄바꿈이 되므로
        #end를 사용해야만 줄바꿈을 방지할 수 있다.
        print(i*int(repeat), end="")
    #줄바꿈 (java의 println느낌)
    print()
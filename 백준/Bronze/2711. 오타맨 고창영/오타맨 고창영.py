T = int(input())
for _ in range(T):
    n, str = input().split()
    n = int(n)
    # sep 함수를 이용해서 띄어쓰기를 안하고 붙여 쓸 수 있다.
    print(str[:n-1],str[n:],sep='')
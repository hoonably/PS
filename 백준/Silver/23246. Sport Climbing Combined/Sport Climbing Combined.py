arr = []
for _ in range(int(input())) :
    n , a , b , c = list(map(int,input().split()))
    arr.append([n,a*b*c,a+b+c])
arr.sort(key=lambda x: (x[1],x[2],x[0]))
print(arr[0][0],arr[1][0],arr[2][0])
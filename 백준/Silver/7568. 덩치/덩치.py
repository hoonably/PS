import sys

N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    arr.append([x,y])

for i in range(N):
    answer = 1
    for a in arr:
        if arr[i][0]<a[0] and arr[i][1]<a[1]:
            answer+=1
    print(answer, end=' ')
import sys

N = int(sys.stdin.readline())
arr = set()
for i in range(N):
    word = sys.stdin.readline().rstrip()
    arr.add(word)

arr = list(arr)

# 2차원 배열 정렬 : 길이 우선
arr.sort()
arr.sort(key=len)

for word in arr:
    print(word)

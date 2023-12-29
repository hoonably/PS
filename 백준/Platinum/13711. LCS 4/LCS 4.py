import sys, bisect

# 입력부
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

# da : 현재 a의 원소의 값을 key, 그 때의 인덱스를 value로 갖는 딕셔너리
da = dict().fromkeys([i for i in range(n + 1)], -1)
# da : 현재 b의 원소의 값을 key, 그 때의 인덱스를 value로 갖는 딕셔너리
db = dict().fromkeys([i for i in range(n + 1)], -1)

for i in range(n):
    da[a[i]] = i
    db[b[i]] = i

# arr : A를 기준으로 하는 B배열의 인덱스 배열. 그림 3의 오른쪽 위 배열 그림과 같다
arr = []
for i in range(n):
    arr.append(db[a[i]])

# lis를 구한다 - O(NlogN)
lis = []
for i in range(n):
    if not lis:
        lis.append(arr[i])
    else:
        if arr[i] > lis[-1]:
            lis.append(arr[i])
        else:
            # idx : lower_bound의 인덱스
            idx = bisect.bisect_left(lis, arr[i])
            lis[idx] = arr[i]

# 정답 출력
print(len(lis))
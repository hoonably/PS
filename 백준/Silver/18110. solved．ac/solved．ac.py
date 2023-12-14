import sys

# 어짜피 소수 첫번째 자리에서 반올리해야 하므로.
# 나머지 경우는 고려안하는 방법을 사용
def round2(num):
    return int(num) + (1 if num - int(num) >= 0.5 else 0)


n = int(sys.stdin.readline())

if n==0:
    print(0)
    quit()

# 15퍼센트 수
cut = round2(n*15/100)

score_arr = []
for _ in range(n):
    score = int(sys.stdin.readline())
    score_arr.append(score)
score_arr.sort()

sum = 0
for i in range(cut, n-cut):
    sum+=score_arr[i]

print(round2(sum/(n-2*cut)))
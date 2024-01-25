import heapq
import sys

def dist(mbti1, mbti2):
    res = 0
    for i in range(4):
        if mbti1[i] != mbti2[i]:
            res+=1
    return res

T = int(input())
for _ in range(T):
    N = int(input())
    mbti = list(sys.stdin.readline().split())
    if N > 32:  # 비둘기집 원리 무조건 같은게 3개 이상 나온다.
        print(0)
        continue
    arr = []
    ans = sys.maxsize
    for i in range(N):
        for j in range(i):
            for k in range(j):
                temp = (dist(mbti[i], mbti[j])
                        + dist(mbti[i], mbti[k])
                        + dist(mbti[j], mbti[k]))
                ans = min(ans, temp)
    print(ans)

import sys
from bisect import bisect_left

input = sys.stdin.readline

n, m, a = map(int, input().split())
S = sorted(list(map(int, input().split())))

low, high = S[0], S[-1]
while low <= high:
    mid = (low + high) // 2

    score, level = 0, mid
    for x in range(m):
        index = bisect_left(S, level)
        if index == 0:
            break

        if index == n and S[index - 1] < level:
            score += S[index - 1] * (m - x)
            break

        score += S[index - 1]
        level += S[index - 1]

    if score >= a:
        high = mid - 1
    else:
        low = mid + 1

print(high)
t = int(input())
for _ in range(t):
    s = int(input())
    n = int(input())
    option = 0
    for _ in range(n):
        q, p = map(int, input().split())
        option += q*p
    print(s+option)
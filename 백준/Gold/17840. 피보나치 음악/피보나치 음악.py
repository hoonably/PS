import sys

Q, M = map(int, sys.stdin.readline().split())

fib = [0]*(M**2)
fib[0], fib[1] = 0, 1
ans = [0, 1]

for i in range(M**2):
    if fib[i] == 1 and fib[i+1] == 0:
        ans.pop()
        break
    fib[i+2] = (fib[i] + fib[i+1]) % M
    ans += list(map(int, str(fib[i+2])))

cycle = len(ans)

for _ in range(Q):
    N = int(sys.stdin.readline())
    print(ans[N%cycle])


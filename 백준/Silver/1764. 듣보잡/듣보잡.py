import sys

n, m = map(int, sys.stdin.readline().split())
not_heard = set()
not_seen = set()
for _ in range(n):
    not_heard.add(sys.stdin.readline().strip())
for _ in range(m):
    not_seen.add(sys.stdin.readline().strip())

#교집합
not_hs = not_heard & not_seen

print(len(not_hs))
for p in sorted(not_hs):
    print(p)
    
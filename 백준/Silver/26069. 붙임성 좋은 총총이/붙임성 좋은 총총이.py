import sys

# 집합 생성
dance = {'ChongChong'}
# 빈 집합 생성할 때는
# dance = set()


N = int(sys.stdin.readline())
for _ in range(N):
    a, b = sys.stdin.readline().split()
    if (a in dance) or (b in dance):
        dance.add(a)
        dance.add(b)
print(len(dance))

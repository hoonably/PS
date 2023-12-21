import sys

T = int(input())
for _ in range(T):
    combo = sys.stdin.readline().strip()
    if len(combo)!=7 or combo[0]==combo[2]:
        print(0)
        continue
    if combo[0]==combo[1]==combo[4] and combo[2]==combo[3]==combo[5]==combo[6]:
        print(1)
    else:
        print(0)
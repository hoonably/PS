import sys

t = int(sys.stdin.readline())
for _ in range(t):
    c, v = map(int, sys.stdin.readline().split())
    print("You get %d piece(s) and "
          "your dad gets %d piece(s)." % (c//v, c%v))
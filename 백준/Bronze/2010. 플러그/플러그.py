# sys.stdin을 이용해야 빠르다.
import sys

N = int(input())
sumPlug = 0
plug = 0
for _ in range(N):
    sumPlug += int(sys.stdin.readline())
    plug += 1

print(sumPlug-plug+1)
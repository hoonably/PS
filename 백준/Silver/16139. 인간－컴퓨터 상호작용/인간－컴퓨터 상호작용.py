import sys

S = sys.stdin.readline().rstrip()

# askii code a~z = 97~122 (26개)
AtoZ = [0]*26
Sum = []

for char in S:
    askii = ord(char)
    AtoZ[askii-97]+=1
    Sum.append(AtoZ.copy())

q = int(sys.stdin.readline())
for _ in range(q):
    find, start, end = sys.stdin.readline().split()
    find = ord(find)-97
    start, end = int(start), int(end)
    # 0도 아래와 같이 해주면 start-1이 -1이되어 엉망이된다.
    if start==0:
        print(Sum[end][find])
    else:
        print(Sum[end][find]-Sum[start-1][find])
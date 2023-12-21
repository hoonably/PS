A, B, C = 5*60, 1*60, 10
T = int(input())
timeA,timeB,timeC = 0,0,0
if T>=A :
    timeA = T//A
    T%=A
if T>=B :
    timeB = T//B
    T%=B
if T>=C :
    timeC = T//C
    T%=C

if T==0:
    print(timeA,timeB,timeC)
else:
    print(-1)
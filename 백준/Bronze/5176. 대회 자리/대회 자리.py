K = int(input())
for _ in range(K):
    P, M = map(int, input().split())
    seat_list = [0 for i in range(M)]
    count = 0
    for _ in range(P):
        i = int(input())
        if seat_list[i-1]==0:
            seat_list[i-1]=1
        else:
            count+=1
    print(count)
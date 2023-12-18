T = int(input())
for _ in range(T):
    score_list = list(map(int,input().split()))
    score_list.sort()
    score_list.pop(-1)
    score_list.pop(0)
    if score_list[-1]-score_list[0]>=4:
        print("KIN")
    else:
        print(sum(score_list))
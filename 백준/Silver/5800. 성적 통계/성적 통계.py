K = int(input())
for class_num in range(1,K+1):
    score_list = list(map(int, input().split()))
    n = score_list.pop(0)
    score_list.sort()

    gap_list = []
    for i in range(n-1):
        gap = score_list[i+1]-score_list[i]
        gap_list.append(gap)

    print("Class", class_num)
    print("Max %d, Min %d, Largest gap %d"
          % (score_list[-1], score_list[0], max(gap_list)))
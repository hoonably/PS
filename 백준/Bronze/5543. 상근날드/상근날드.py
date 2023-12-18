burger_list = []
burger_list.append(int(input()))
burger_list.append(int(input()))
burger_list.append(int(input()))
bev_list = []
bev_list.append(int(input()))
bev_list.append(int(input()))

burger_list.sort()
bev_list.sort()
print(burger_list[0]+bev_list[0]-50)
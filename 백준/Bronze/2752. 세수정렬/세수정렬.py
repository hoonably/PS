num_list = list(map(int,input().split()))
num_list.sort()
# 리스트를 [] 없이 띄어서 출력
# 리스트 앞에 *를 붙이면 된다.
print(*num_list)
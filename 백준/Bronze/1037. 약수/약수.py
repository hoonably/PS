n = int(input())
div_list = list(map(int, input().split()))
div_list.sort()
print(div_list[0]*div_list[-1])
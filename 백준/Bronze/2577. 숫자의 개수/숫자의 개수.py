a = int(input())
b = int(input())
c = int(input())

#int to String
num = str(a*b*c)

# 크기가 10이고 모두 0인 리스트 생성
num_list = [0 for i in range(10)]

for eachnum in num:
    #다시 int로 형변환해줘야 list에 들어감
    num_list[int(eachnum)] += 1

for i in num_list:
    print(i)
import sys

num_list = []

N = int(sys.stdin.readline())
for _ in range(N):
    num = int(sys.stdin.readline())
    num_list.append(num)

num_list.sort()
# 산술평균
def avg(list):
    return sum(list)/len(list)
# 중앙값
def mid(list):
    return list[len(list)//2]
# 최빈값
def mode(list):
    #받는 리스트가 한개의 원소일 경우 그냥 바로 그 값 출력
    if len(list)==1:
        return list[0]

    mode_list = [] # 최빈값들의 리스트
    most = 0 # 최빈값 반복 횟수
    n = 0 # 반복 횟수
    for i in range(1,len(list)):
        if list[i]==list[i-1]:
            n += 1
            if n>most:
                most = n
                mode_list.clear() # 기존의 최빈값 다 지우기
                mode_list.append(list[i])
            elif n==most:
                mode_list.append(list[i])
        else:
            n=0
    if len(mode_list)==0:
        return list[1]
    elif len(mode_list)==1:
        return mode_list[0]
    else:
        return mode_list[1]


# 범위
def list_range(list):
    return list[-1]-list[0]

# round 함수를 사용하여 정수로 반올림 할 수 있다.
print(round(avg(num_list)))
print(mid(num_list))
print(mode(num_list))
print(list_range(num_list))

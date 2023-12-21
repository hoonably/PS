N, M = map(int,input().split())
s_list = []

def sequence():
    if len(s_list)==M:
        print(*s_list)
        return

    for i in range(1,N+1):
        #중복일경우 추가 안하고 넘기기
        if i in s_list:
            continue
        s_list.append(i)
        sequence()
        s_list.pop()

sequence()
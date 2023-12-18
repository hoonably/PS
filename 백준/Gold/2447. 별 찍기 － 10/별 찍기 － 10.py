def star(n):
    if n == 1:
        return ['*']
    #이전단계의 별 재귀로 불러오기
    last_star = star(n//3)
    result = []
    for ls in last_star:
        result.append(ls * 3) # 한 줄
    for ls in last_star:
        result.append(ls + ' '*(n//3) + ls)
    for ls in last_star:
        result.append(ls * 3)
    #리스트를 리턴
    #리스트의 하나의 원소는 한 '줄'을 나타냄
    return result

N = int(input())

for i in star(N):
    print(i)
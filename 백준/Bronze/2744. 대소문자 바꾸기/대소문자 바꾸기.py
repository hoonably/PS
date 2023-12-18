S = input()
for i in S:
    if i.isupper(): #대문자면 True 반환
        i = i.lower() #소문자로 변경
    else:
        i = i.upper() #대문자로 변경
    print(i, end='')
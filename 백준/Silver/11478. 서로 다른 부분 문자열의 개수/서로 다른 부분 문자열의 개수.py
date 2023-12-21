s = input()

str_set = set()

for i in range(len(s)):
    for j in range(i,len(s)):
        #i부터 j번째 글자로 문자열 생성
        str_set.add(s[i:j+1])

print(len(str_set))
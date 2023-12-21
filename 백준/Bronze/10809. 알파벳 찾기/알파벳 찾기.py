S = input()
# a부터 z까지 크기가 26이고 모두 0인 리스트 만들기
alphabet_list = [-1 for i in range(26)]

#for문을 거꾸로 돌리는 법 reversed() 사용
for i in reversed(range(len(S))):
    askii_code = ord(S[i])
    alphabet_list[askii_code-97] = i
print(*alphabet_list)
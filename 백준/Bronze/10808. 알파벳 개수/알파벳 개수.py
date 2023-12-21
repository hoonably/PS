S = input()
# a부터 z까지 크기가 26이고 모두 0인 리스트 만들기
alphabet_list = [0 for i in range(26)]

for i in S:
    askii_code = ord(i)
    # 97부터 a이므로
    alphabet_list[askii_code-97] += 1
print(*alphabet_list)
str = input()
# A부터 Z까지 크기가 26이고 모두 0인 리스트 만들기
a = [0 for i in range(26)]
for i in str:
    i = i.upper()
    askii_code = ord(i) # 문자를 아스키코드로 변환
    a[askii_code - 65] += 1

max = -1
max_a = '?'

for i in range(len(a)):
    if a[i]>max: # 최대값이 바뀌는 경우
        max = a[i]
        max_a = chr(i+65) # 아스키 코드를 문자로 변환
    elif a[i]==max: # 최대값이 두개일 경우
        max_a = '?'

print(max_a)

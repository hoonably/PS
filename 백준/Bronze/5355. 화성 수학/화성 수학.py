T = int(input())

for _ in range(T):
    mars = list(input().split())
    result = 0
    for i in mars:
        if i == '@':
            result *= 3
        elif i == '%':
            result += 5
        elif i == '#':
            result -= 7
        else:
            result += float(i)
    
    # 소수점 둘째자리까지 출력
    print("{:.2f}".format(result))

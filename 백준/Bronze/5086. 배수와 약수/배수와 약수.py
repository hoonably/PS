while True:
    a, b = map(int, input().split())
    if a==b==0:
        break
    elif a<b:
        if b%a==0:
            print("factor")
        else:
            print("neither")
    elif a>b:
        if a%b==0:
            print("multiple")
        else:
            print("neither")
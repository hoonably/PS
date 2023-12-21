n = int(input())
for _ in range(n):
    p = int(input())
    best_price = 0
    best_name = ""
    for _ in range(p):
        price, name = input().split()
        price = int(price)
        if(price>best_price):
            best_price = price
            best_name = name
    print(best_name)
dish = input()
high = 0
for i in range(len(dish)):
    if i==0:
        high+=10
    elif dish[i] == dish[i-1]:
        high+=5
    else:
        high+=10
print(high)
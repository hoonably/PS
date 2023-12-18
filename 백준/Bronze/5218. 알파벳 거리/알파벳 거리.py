t = int(input())
for _ in range(t):
    a, b = input().split()
    dt_list = []
    for i in range(len(a)):
        distance = ord(b[i])-ord(a[i])
        if distance<0:
            distance+=26
        dt_list.append(distance)
    print("Distances:", *dt_list)
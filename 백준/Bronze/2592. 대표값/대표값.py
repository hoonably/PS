import statistics

list = []
for _ in range(10):
    list.append(int(input()))
print(int(sum(list)//10))

#최빈값 (Mode) 
print(statistics.mode(list))
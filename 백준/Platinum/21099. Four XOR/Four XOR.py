n = int(input())
if n > 60:
    print("Yes")
    exit()
else:
    input_list = list(map(int, input().split()))
    result = input_list[0]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                for m in range(n):
                    result = (input_list[i] ^ input_list[j] ^ input_list[k] ^ input_list[m])
                    if result == 0:
                        if input_list[i] < input_list[j] < input_list[k] < input_list[m]:
                            print("Yes")
                            exit()
print("No")

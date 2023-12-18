for _ in range(3):
    result = list(map(int, input().split()))
    # count 함수 이용
    if result.count(0) == 1:
        print("A")
    elif result.count(0) == 2:
        print("B")
    elif result.count(0) == 3:
        print("C")
    elif result.count(0) == 4:
        print("D")
    else:
        print("E")
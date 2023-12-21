T = int(input())
for i in range(T):
    scoreYonsei, scoreKorea = 0, 0
    for j in range(9):
        y, k = map(int, input().split())
        scoreYonsei += y
        scoreKorea += k
    if scoreYonsei>scoreKorea:
        print("Yonsei")
    elif scoreYonsei<scoreKorea:
        print("Korea")
    else:
        print("Draw")
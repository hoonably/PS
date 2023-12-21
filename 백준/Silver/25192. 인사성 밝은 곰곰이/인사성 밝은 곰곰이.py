import sys

N = int(input())
answer = 0
name_set = set()

for _ in range(N):

    chat = sys.stdin.readline()
    # readline으로 읽으면 엔터까지 읽어서 비교할때 이렇게 해줘야한다.
    if chat == 'ENTER\n':
        name_set.clear() #clear함수 사용

    # 리스트에 값이 있는지 확인 : in 사용
    # 을 하면 시간복잡도가 O(N)으로 매우 느리게 동작한다.
    # 그래서 시간 초과를 막기 위해선 list말고 set을 사용해야한다.
    elif chat not in name_set:
        answer += 1
        name_set.add(chat)
print(answer)

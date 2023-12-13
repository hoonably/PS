from collections import deque

N = int(input())
card = deque(range(1,N+1))

while len(card)>1:
    # 카드 버리기
    card.popleft()
    # 카드 아래로 옮기기
    card.append(card.popleft())

print(card.popleft())

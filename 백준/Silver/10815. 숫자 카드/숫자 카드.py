N = int(input())
card = set(map(int, input().split()))
M = int(input())
# s_card 도 set으로 만들면 순서가 엉망이라 list로 만든다.
s_card = list(map(int, input().split()))

for c in s_card:
    if c in card:
        print(1, end=' ')
    else:
        print(0, end=' ')
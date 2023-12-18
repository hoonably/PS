n = int(input())
list = []

for _ in range(n):
    name, d, m, y = input().split()
    # map 사용으로 int형 변환
    d,m,y = map(int,(d,m,y))
    # 이차원배열에 값 추가 (정렬 우선순서대로)
    list.append((y,m,d,name))
list.sort()
print(list[-1][3])
print(list[0][3])
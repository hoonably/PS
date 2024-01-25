import sys
def make_list(usable):
    last_list = usable.copy()
    use_num.append(last_list.copy())
    if '0' in last_list:
        last_list.remove('0')

    for _ in range(6):
        next_list = []
        for last in last_list:
            for plus in usable:
                next_list.append(last+plus)
        use_num.append(next_list)
        last_list = next_list.copy()

N = int(input())
M = int(input())
if M==0:
    best = min(len(str(N)), abs(N - 100))
    print(best)
    quit()
broken = list(sys.stdin.readline().split())
usable = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
for i in broken:
    usable.remove(i)

# 리모컨으로 999999까지 누르는 경우까지 생각해줘야함
# 1번 누르는 경우부터 7번 누르는 경우까지
use_num = [[]]
make_list(usable)

best = 500000
# 숫자 1번 누르는거부터 6번 누르는거까지
for i in range(1,7):
    for j in range(len(use_num[i])):
         remote = int(use_num[i][j])
         making = abs(remote-N)+len(str(remote))
         best = min(best, making)

# 숫자 안누르고 100에서 시작하는 경우
best = min(best, abs(N - 100))

print(best)
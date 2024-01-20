import sys

# [set(), {'U', 'N', 'I', 'T', 'S'}, {'UN', 'IS', 'NI', 'ST'},
# {'IST', 'NIS', 'UNI'}, {'UNIS', 'NIST'}, {'UNIST'}] 생성
correct = [set() for _ in range(6)]
for i in range(5):
    for j in range(i + 1, 6):
        correct[j-i].add('UNIST'[i:j])

def compare(x):
    # 검사할 범위
    length = min(5, len(x))
    for l in reversed(range(1, length+1)):  # 최대 5부터 1까지 검사
        if x[:l] in correct[l]:  # 앞에서부터 l개 커팅한게 집합에 있는지
            return l  # 맞은 개수만큼 리턴
    return 0

dp = [0] * 6
dp[0] = 1

N = int(sys.stdin.readline())

for _ in range(N):
    st = sys.stdin.readline().rstrip()
    if not st[0] in 'UNIST':  # 불필요한 단어 미리 삭제
        continue

    # 시작지점 : U:1, N:2 이런식으로
    start = 'UNIST'.index(st[0]) + 1

    # 맞는 길이
    corlen = compare(st)

    for i in range(start, start + corlen):
        dp[i] += dp[start - 1]
        dp[i] %= 1000000007

print(dp[-1])

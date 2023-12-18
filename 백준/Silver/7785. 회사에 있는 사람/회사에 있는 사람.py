import sys

# 딕셔너리 생성
log_dic = {}

n = int(sys.stdin.readline())
for _ in range(n):
    person, log = sys.stdin.readline().split()
    if log == 'enter':
        log_dic[person]=log
    else:
        # 딕셔너리 삭제 방법
        del log_dic[person]

# 역순으로 정렬해서 for문
for answer in sorted(log_dic, reverse=True):
    print(answer)

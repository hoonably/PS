import sys

N, M = map(int, sys.stdin.readline().split())

pw_dic = {}
for _ in range(N):
    site, pw = sys.stdin.readline().split()
    pw_dic[site] = pw
for _ in range(M):
    get_site = sys.stdin.readline().rstrip()
    print(pw_dic[get_site])
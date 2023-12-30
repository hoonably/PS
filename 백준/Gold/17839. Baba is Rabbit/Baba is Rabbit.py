import sys

N = int(input())

dic = {}
answer_set = set()
stack = ['Baba']

for _ in range(N):
    key, value = sys.stdin.readline().rstrip().split(' is ')
    if key not in dic:
        dic[key] = {value}
    else:
        dic[key].add(value)

while stack:
    current_key = stack.pop()
    if current_key not in dic:
        continue
    for i in dic[current_key]:
        if i not in answer_set:
            answer_set.add(i)
            stack.append(i)

answer_list = sorted(answer_set)
for i in answer_list:
    print(i)

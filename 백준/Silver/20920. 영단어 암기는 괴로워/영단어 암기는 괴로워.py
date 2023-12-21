import sys

N, M = map(int, sys.stdin.readline().split())
dic = {}
for _ in range(N):
    word = sys.stdin.readline().strip()

    # 단어 길이가 M보다 짧으면 패스
    if len(word)<M:
        continue

    if word not in dic:
        dic[word] = 1
    else:
        dic[word] += 1
# 다중 조건 정렬 !!!!!!!!!!!
# sorted 함수는 다중 조건으로 정렬 가능하다!!!
word_list = sorted(dic.items(), key=lambda x : (-x[1], -len(x[0]), x[0]))

# 정렬 과정에서 딕셔너리가 아닌 리스트로 바뀌었다.
for word in word_list:
    print(word[0])
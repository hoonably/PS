import sys

T = sys.stdin.readline().rstrip()
P = sys.stdin.readline().rstrip()
lps = [0]*len(P)
ans = []

# 접두사와 접미사가 일치하는 가장 긴 길이 저장
def makeLps(p, lps):
    length = 0

    i = 1
    while i < len(p):
        if p[length] == p[i]:
            length += 1
            lps[i] = length
            i += 1

        else:
            if length == 0:
                lps[i] = 0
                i += 1
            else:
                length = lps[length - 1]



def KMP(T, P):
    lenT, lenP = len(T), len(P)
    i, j = 0, 0
    while i < lenT:
        # 동일하면 전진
        if T[i]==P[j]:
            i+=1
            j+=1
        # 동일하지 않고 보고있는게 0번째가 아니면
        # 봐야하는 lps부터 보기
        elif j!=0:
            j = lps[j-1]
        # 동일하지 않고 0번째면 그냥 다음으로
        else:
            i+=1

        # print(i, j)
        if j==lenP:
            ans.append(i-lenP+1)
            j = lps[j-1]

makeLps(P, lps)
KMP(T,P)

print(len(ans))
if ans:
    print(*ans)

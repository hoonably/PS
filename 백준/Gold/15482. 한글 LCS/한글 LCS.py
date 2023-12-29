str1 = input()
str2 = input()

n = len(str1)
m = len(str2)

# dp[j] : 두번째 수열 j번째 인덱스까지 LCS
dp=[0]*m

for i in range(n):
    cnt = 0
    for j in range(m):
        if cnt < dp[j]:
            cnt = dp[j]
        elif str1[i] == str2[j]:
            dp[j] = cnt + 1

print(max(dp))

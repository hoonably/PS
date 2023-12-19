problem = input()

# -를 기준으로만 스플릿
nums = list(problem.split('-'))

# +가 사이에 있으면 계산한 값으로 리스트에 다시 대입
for i in range(len(nums)):
    plus = map(int, nums[i].split('+'))
    nums[i]=sum(plus)

# 첫번째는 무조건 양수
answer = nums[0]
# 두번째부터 다 마이너스 해주기
for i in range(1,len(nums)):
    answer-=nums[i]
print(answer)
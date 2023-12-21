N = int(input())
answer = 0
for _ in range(N):
    students, apple = map(int, input().split())
    answer += apple % students
print(answer)
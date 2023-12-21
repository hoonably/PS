str = input()

answer = 0
for alphabet in str:
    if (alphabet=='a' or alphabet=='e' or
            alphabet=='i' or alphabet=='o' or alphabet=='u'):
        answer+=1
print(answer)
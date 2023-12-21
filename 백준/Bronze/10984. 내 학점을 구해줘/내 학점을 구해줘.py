T = int(input())
for _ in range(T):
    N = int(input())
    total_grade = 0
    total_sum = 0
    for _ in range(N):
        C, G = map(float, input().split())
        total_grade += C
        total_sum += G * C
    GPA = total_sum / total_grade
    # 정수출력, 소수점 1째자리까지 출력
    print("%d %.1f" % (total_grade, GPA))
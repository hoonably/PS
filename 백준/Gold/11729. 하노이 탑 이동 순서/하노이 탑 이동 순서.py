def hanoi(n, start, end): # (1~n 번을, start에서, end로 옮김)
    if n==1:
        print(start, end)
        return
    # 옮기려는 곳 말고 다른 곳으로 옮기기
    # 6-start-end 를 하면 start 와 end 외의 곳이다.
    not_start_end = 6-start-end
    # 1단계 : 마지막 것을 제외한 모든 것을 옮긴다.
    hanoi(n-1, start, not_start_end)

    # 2단계 : 마지막 것을 옮긴다.
    print(start, end)

    # 3단계 : 1단계에서 옮겨서 남은 1 ~ n-1 번을 end 로 옮긴다.
    hanoi(n-1, not_start_end, end)

N = int(input())
# 옮긴 횟수: 2의 n승 -1번
print(2**N-1)
# 1~N번을 1번 자리에서 3번 자리로 옮긴다.
hanoi(N,1,3)

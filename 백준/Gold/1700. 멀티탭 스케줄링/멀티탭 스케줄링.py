# 1700
import sys


N, K = map(int, sys.stdin.readline().split())
if N>=K:
    print(0)
    exit()

seq = list(map(int,sys.stdin.readline().split()))

plug_on = set()
answer = 0

# 중요!:
# idx 이후에 남은 것중에 가장 나중에 나오하는 원소를 뽑는다.
def find_latest(idx):
    result = 0
    last_idx = -1
    for num in plug_on:
        # 에러가 날 수 있는 부분
        try:
            num_idx = seq[idx:].index(num)
        # num이 seq에 없다면 error 발생하니까 발동
        except:
            num_idx = K
        # 가장 나중에 나올때의 그 수를 리턴
        if last_idx < num_idx:
            result = num
            last_idx = num_idx
    return result


# enumerate() 함수 : (인덱스, 값)으로 리스트를 바꿔준다.
for idx, num in enumerate(seq):
    # 집합에 넣어주기 (중복 알아서 처리됨)
    plug_on.add(num)
    # 플러그수가 부족하면 뽑아야함
    if len(plug_on)>N:
        answer+=1
        # 마지막으로 나오는것을 뽑기
        plug_on.discard(find_latest(idx))
        
print(answer)
    
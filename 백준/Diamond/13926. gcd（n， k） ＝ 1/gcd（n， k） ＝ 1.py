import sys

# a의 b제곱을 m으로 나눈 나머지를 빠르게 계산해주는 함수
# 기존의 a**b를 사용하며 m으로 나눈 나머지를 구하면 오래걸린다.
def powmod(a,b,m):
    result = 1
    while b > 0:
        if b % 2 != 0:
            result = (result * a) % m
        b //= 2
        a = (a * a) % m

    return result

# 밀러 라빈 소수 판별 (큰 수에서 유용)
def mr(n,a):
    r = 0
    d = n-1
    while (d%2 == 0):
        r += 1
        d = d // 2
    x = powmod(a,d,n)
    # a의 d제곱을 n으로 나눈 나머지가 +-1 이면 True
    if x == 1 or x == n-1:
        return True
    for i in range(0,r-1):
        x = powmod(x,2,n)
        if x == n-1:
            return True
    return False

# 소수가 맞는지 확인 함수
def check_prime(k):
    check = 0
    # 작은수에서
    if k <= 71:
        if k in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]:
            return True
        else:
            return False
    # 큰 수에서
    else:
        for i in [ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
            if mr(k,i) == False:
                return False
        # 위의 12개의 소수들을 k로 나눈 나머지가 다 True면 소수로 취급
        return True

n = int(sys.stdin.readline())
ori_n = n

# a와 b의 최대공약수 함수
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

# 제곱하여 1 더한 값을 n으로 나눈 나머지
def g(x,n):
    return (x**2 + 1) % n

# 폴라드 로 알고리즘
def pola(n,x):
    p = x
    if check_prime(n):
        return n
    else:
        for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]:
            if n % i == 0:
                return i
        y = x
        d = 1
        while d == 1:
            x = g(x,n)
            y = g(g(y,n),n)
            d = gcd(abs(x-y),n)
        if d == n:
            return pola(n,p+1)
        else:
            if check_prime(d):
                return d
            else:
                return pola(d,2)
ans = []

while n != 1:
    k = pola(n,2)
    ans.append(int(k))
    n = n // k



from itertools import combinations

check_sum = ori_n
ans = list(set(ans))
for i in range(1,len(ans)+1):
    for t in combinations(ans,i):
        k = 1
        for p in t:
            k *= p
        if i % 2 == 1:
            check_sum -= (ori_n // k)
        else:
            check_sum += (ori_n // k)

if ori_n == 1:
    print(1)
else:
    print(check_sum)

# N = 30 의 예시

# 30의 경우 소수가 2,3,5 이므로 30 / 2 = 15 , 30 / 3 = 10 , 30 / 5 = 6이다.
# 일단 중복 생각 안 하고 전체 30개에서 15 , 10 , 6 개를 빼주니 -1이다.
# 중복을 고려해야 하니 (2,3 = 6) , (2,5 = 10) , (3,5 = 15)를 30에서 나누어 준다.

# 30 / 6 = 5 , 30 / 10 = 3 , 30 / 15 = 2 이므로 다시 -1에서 +5 +3 + 2를 해준다.
# 왜냐하면 6의 배수 , 10의 배수 , 15의 배수들은 이미 위에서 겹쳐져서 2번 빼준 것들 이기 떄문에 +1 씩 해주는 것이다.

# 그러면 또 6 , 10 , 15 의 공배수는 또 여러번 더해준 상태가 되니 이부분을 제거 해야한다.
# 예를 들어 30의 경우 , 6 , 10 , 15 의 배수면 +1 하기로 했으니 6에서 , 10에서 , 15에서 각각 +1이 3번 되었을 것이다.
# 그렇기에 주어진 소인수들로 만들 수 있는 모든 조합에 대해서 보정해주어야 한다.

# 즉 이전단계에 보정을 더해주었으니 마지막 2,3,5를 모두 사용한 30 / 30 = 1 은 빼주어야 한다는 뜻이 된다.

# 위의 예시를 천천히 읽으면 바로 소인수들의 조합으로 체크할 수를 만들 때 ,
# 사용한 소인수의 개수가 홀수면 n에서 빼주고 , 짝수면 더해주면 된다는 사실을 알 수 있다.
# 이를 통해 나누어서 0이 한번이라도 나온 수들의 개수를 중복을 제외하고 셀 수 있다는 것이다.

# 마무리를 내자면 (2,3,5 = 30)이고 이는 소인수 3개 즉 홀수 개수로 만들었으므로 빼주어야 한다.
# 따라서 N = 30의 답은 9 - 1 = 8로 나오게 된다.
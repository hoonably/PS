import random

def miller_rabin(n, k=5):
    if n == 2 or n == 3:
        return True
    if n == 1 or n % 2 == 0:
        return False

    # Write n as 2^r * d + 1
    r, d = 0, n - 1
    while d % 2 == 0:
        r += 1
        d //= 2

    # Witness loop
    for _ in range(k):
        a = random.randint(2, n - 2)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def pollards_rho(n, attempts=50):
    for _ in range(attempts):
        x = random.randint(1, n - 1)
        y = x
        c = random.randint(1, n - 1)
        d = 1

        f = lambda x: (x ** 2 + c) % n

        while d == 1:
            x = f(x)
            y = f(f(y))
            d = gcd(abs(x - y), n)

        if d != n:
            return d
    return n

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def factorize(n):
    factors = []

    # Step 1: Try simple division with small primes
    for i in range(2, 38):  # 37까지만 검사
        if n % i == 0:
            factors.append(i)
            n //= i
            while n % i == 0:
                factors.append(i)
                n //= i

    # Step 2: If not found, use Pollard's Rho
    while n > 1:
        if miller_rabin(n):
            factors.append(n)
            break
        divisor = pollards_rho(n)
        factors.append(divisor)
        n //= divisor

    return factors

number = int(input())
result = factorize(number)
result.sort()

for i in result:
    print(i)

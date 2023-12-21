import sys


def recursion(s, l, r, call):
    call += 1
    if l >= r: return [1, call]
    elif s[l] != s[r]: return [0, call]
    else: return recursion(s, l+1, r-1, call)

def isPalindrome(s, call):
    return recursion(s, 0, len(s)-1, call)

T = int(sys.stdin.readline())
for _ in range(T):
    S = sys.stdin.readline().strip()
    call = 0
    print(*isPalindrome(S, call))

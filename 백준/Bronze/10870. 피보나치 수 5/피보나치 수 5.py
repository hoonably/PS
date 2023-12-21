def pibonachi(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return pibonachi(n-2)+pibonachi(n-1)

n = int(input())
print(pibonachi(n))

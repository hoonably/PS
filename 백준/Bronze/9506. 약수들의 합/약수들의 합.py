def divisor(n):
    divlist = []
    for i in range(1, int(n**(1/2)+1)):
        if n%i==0:
            divlist.append(i)
            # i**2==n이면 중복으로 두개가 들어갈 수 있으므로
            if i**2!=n:
                divlist.append(n//i)
    divlist.sort()
    return divlist

while True:
    n = int(input())
    if n==-1:
        break
    divlist = divisor(n)
    if sum(divlist) == 2 * n:
        print(n, end=' = ')
        for i in range(len(divlist)-2):
            print(divlist[i], end=' + ')
        # 마지막에서 두번째는 따로 출력
        print(divlist[-2])
    else:
        print(n, "is NOT perfect.")
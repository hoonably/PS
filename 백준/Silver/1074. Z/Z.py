import sys

def which_square(n):
    global r, c
    mid_cut = 2**(n-1)
    # print("midcut",mid_cut)
    if r<mid_cut:
        if c<mid_cut:
            return 0
        else:
            c-=mid_cut
            return 1
    else:
        r-=mid_cut
        if c<mid_cut:
            return 2
        else:
            c-=mid_cut
            return 3

def make_square_list(n,r,c):
    global ans
    ans += 4**(n-1) * which_square(n)
    if n==1:
        print(ans)
        return
    make_square_list(n-1,r,c)



N, r, c = map(int, sys.stdin.readline().split())
ans = 0
make_square_list(N,r,c)

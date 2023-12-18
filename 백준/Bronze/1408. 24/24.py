h1, m1, s1 = map(int, input().split(':'))
h2, m2, s2 = map(int, input().split(':'))

h = h2-h1
m = m2-m1
s = s2-s1
if s<0:
    m-=1
    s+=60
if m<0:
    h-=1
    m+=60
if h<0:
    h+=24

# %02d => 1~2째자리 출력
print("%02d:%02d:%02d"%(h,m,s))
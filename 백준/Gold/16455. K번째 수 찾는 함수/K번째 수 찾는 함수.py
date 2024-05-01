import random
def kth(a,k):
    def quickselect(a,i,j,k):
        p=a[random.randint(i,j-1)]
        s=i-1;e=j;n=i
        while n<e:
            if a[n]<p:s+=1;a[n],a[s]=a[s],a[n]
            if a[n]>p:e-=1;a[n],a[e]=a[e],a[n];n-=1
            n+=1
        if k>=e:
            return quickselect(a,e,j,k)
        if k<=s:
            return quickselect(a,i,s+1,k)
        return p
    return quickselect(a,0,len(a),k-1)
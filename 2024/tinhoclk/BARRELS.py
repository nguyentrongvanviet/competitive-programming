n , k = map(int,input().split())
a = list(map(int,input().split()))
a.insert(0,0)
a.sort() 
for i in range(n-k,n) : 
    a[n]+=a[i] ; 
    a[i] = 0 
for i in range(1,n+1) : 
    a[1] = min(a[1],a[i]) 
print(a[n]-a[1])   
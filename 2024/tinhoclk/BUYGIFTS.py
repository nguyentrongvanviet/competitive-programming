n , m = map(int,input().split()) 
a = list(map(int,input().split()))
a.sort()
a.append(0) 
res = int(1e9)  
for i in range(m-1,n,1) : 
    res = min(res,a[i]-a[i-m+1]) 
print(res)  
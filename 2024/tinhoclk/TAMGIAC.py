n = int(input()) 
a = list(map(int,input().split()))
res = 0 
a.sort() 
for i in range(n) : 
    t = i+1 
    for j in range(i) :
        while t!=n and a[i]+a[j] > a[t]: t+=1
        res+=t-i-1  
print(res)  

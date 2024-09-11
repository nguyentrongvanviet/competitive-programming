n = int(input())
a = list(map(int,input().split()))
last={} 
res = int(1e9) 
for i in range(n) : 
    if a[i] in last : 
        res=min(res,i-last[a[i]]) 
    last[a[i]] = i
if res == int(1e9) : 
    print(-1) 
else : print(res)   

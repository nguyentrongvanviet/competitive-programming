n , m  = map(int,input().split())

xx = [-1,0,1,0] 
yy = [0,1,0,-1]

a = [[0]*(m+2)]
for i in range(n) : 
    tmp = list(map(int,input().split()))
    tmp.insert(0,0) 
    tmp.insert(m+1,0) 
    a.append(tmp)
a.append([0]*(m+2))
sl = [0]*int(5e3+1)
for i in range(1,n+1) : 
    for j in range(1,m+1) :  
        sum = a[i][j] 
        for u in range(4) : 
            sum+=a[xx[u]+i][yy[u]+j]
        sl[sum]+=1
res = 0 
value = 0 
for i in range(int(5e3),0,-1) :  
    if value<sl[i]: 
        value=sl[i]
        res = i
print(res) 

n = int(input()) 
a = list(map(int, input().split()))

res = [] 
for i in range(1,n-1) : 
    if a[i] > a[i-1] and a[i] > a[i+1] : 
        res.append(a[i])  
print(len(res)) 
for i in res : print(i, end =" ") 

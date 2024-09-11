cam , n = map(int,input().split()) 
a = list(map(int,input().split())) 
a.sort()
res , value = 0 , 0  
for i in range(n) :
    if res < a[i]*min(cam,n-i) : 
        res=a[i]*min(cam,n-i)      
        value = a[i] 
print(value,res) 
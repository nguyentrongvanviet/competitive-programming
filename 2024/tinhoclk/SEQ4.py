n = int(input())
a=[0] 
for i in range(n) : 
    a.append(int(input()))     
dec = [[0,0]] 
res = 0  
sum = 0 
for i in range(1,n+1) : 
    sum+=a[i]  
    l = 0 
    r = len(dec)-1 
    ans = -1 
    while l<=r : 
        mid = (l+r)//2 
        if sum>dec[mid][0] : 
            ans = dec[mid][1]
            r=mid-1 
        else : 
            l=mid+1
    if ans == -1 : 
        dec.append([sum,i])  
    else :
        res = max(res,i-ans) 
print(res)
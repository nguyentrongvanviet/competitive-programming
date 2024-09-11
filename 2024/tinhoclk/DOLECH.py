n , k = map(int,input().split())
a=list(map(int,input().split()))
# print(a)
sl = {} 
res = 0  
for x in a : 
    if x in sl : 
        sl[x]+=1
    else : 
        sl[x]=1 
    if (x-k) in sl : 
        res+=sl[x-k] 
    if x+k in sl : 
        res+=sl[x+k]
print(res) 
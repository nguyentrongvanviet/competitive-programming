n , q = map(int,input().split())
s = [0]*(n+2) 
for i in range(q) : 
    l , r = map(int,input().split()) 
    s[l]+=1
    s[r+1]-=1
res = 0 
for i in range(1,n+1): 
    s[i]+=s[i-1] 
    if s[i]%3==0 : res+=1 
print(res) 
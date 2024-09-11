n = int(input())
a = list(map(int,input().split())) 
a.sort()
s = [0] 
for i in range(n) : 
    s.append(s[i]+a[i])
last = {} 
last[0] = 0
res = 0  
for i in range(1,n+1,1) : 
    if s[i] in last : res=max(res,i-last[s[i]]) 
    else : last[s[i]] = i
print(n-res)  
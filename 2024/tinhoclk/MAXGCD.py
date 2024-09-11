import math 
n = int(input()) 
a = list(map(int,input().split())) 
a.insert(0,0) 
a.insert(n+1,0)
Lgcd = [0]*(n+2) 
Rgcd = [0]*(n+2) 
for i in range(1,n+1) : 
    Lgcd[i] = math.gcd(Lgcd[i-1],a[i])
for i in range(n,0,-1) : 
    Rgcd[i] = math.gcd(Rgcd[i+1],a[i]) 
res = 0 
for i in range(1,n+1) : 
    res = max(res,math.gcd(Lgcd[i-1],Rgcd[i+1]))
print(res) 
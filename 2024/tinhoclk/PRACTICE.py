class DL : 
    def __init__(self,a,b) : 
        self.a=a 
        self.b=b 
    def __lt__(self,other) : 
        return self.a<other.a 
n,C = map(int,input().split())
a = []
for i in range(n) : 
    x,y= map(int,input().split()) 
    a.append(DL(x,y)) 
a.sort()
res = 0 
for i in range(n) : 
    if C>=a[i].a: 
        C+=a[i].b 
        res+=1
    else : break
print(res)  
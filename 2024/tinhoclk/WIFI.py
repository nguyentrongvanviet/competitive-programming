class pt : 
    def __init__(self,x,y) : 
        self.x=x
        self.y=y 
def dis2(a,b) :
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)  
n , radius = map(int,input().split()) 
radius =radius*radius 
a = [] 
for i in range(n) : 
    x,y = map(int,input().split())
    a.append(pt(x,y)) 
res = 0 
for u in a : 
    tmp = 0 
    for v in a : 
        if dis2(u,v)<=radius : 
            tmp+=1
    res=max(res,tmp) 
print(res)   
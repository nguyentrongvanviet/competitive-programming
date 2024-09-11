class pt :
    def __init__(self,a,b) : 
        self.x=a 
        self.y=b 

n = int(input())
a =[pt(0,0)] 
Dx = {} 
Dy = {}
for i in range(n) :
    x,y = map(int,input().split())  
    a.append(pt(x,y))
    Dx[x]= 0 
    Dy[y]= 0 
for i in range(1,n+1) : 
    Dx[a[i].x]+=1
    Dy[a[i].y]+=1 
res = 0 
for i in range(1,n+1) : 
    res+=(Dx[a[i].x]-1)*(Dy[a[i].y]-1) 
print(res)

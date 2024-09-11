n = int(input())
a = list(map(int,input().split())) 
m = int(input())
class D :
    def __init__(self, a, b ) : 
        self.a = a 
        self.b = b 
    def __lt__(self, other) : 
        return self.a<other.a or ( self.a==other.a and self.b<other.b) 
    def __str__(self) : 
        return f"({self.a} {self.b})"
AC = []
for i in range(m) : 
    X,Y = map(int,input().split())  
    AC[i].append(D(X,Y)) 
AC.sort()
mi = int(1e9) 
for i in range(m-1,-1,-1): 
    mi = min(mi,AC[i].b)
    AC[i].b = mi 
 
res = 0 
for i in range(n) : 
    l = 0 
    r = m-1 
    ans = 0
    while l <=r : 
        mid = (l+r)//2
        if AC[mid].a>=a[i] : 
            ans = mid 
            r=mid-1 
        else  : 
            l=mid+1
    res+=AC[ans].b 
print(res) 

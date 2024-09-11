s = input() 
n = len(s)  
if n<3 : print(-1)
else :
    res = -1  
    for i in range(1,n//2-(n%2==0)+1) : 
        if s[:i]==s[-i:] : 
            res=i
    print(res) 
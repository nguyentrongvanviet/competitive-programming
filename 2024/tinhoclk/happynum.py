t = int(input())
def transform( x ) :   
    sum = 0 
    while x: 
        sum+=(x%10)*(x%10)
        x=x//10 
    return sum 
exist = [0]*(int(1e6)+1) 
a=list() 
for _ in range(t) : 
    x = int(input())
    while x!=1 : 
        if exist[x] : 
            break 
        a.append(x) 
        exist[x]=1  
        x =transform(x)
    if x == 1 : 
        print("YES") 
    else :
        print("NO") 
    for value in a : 
        exist[value] = 0  
    a.clear() 
 
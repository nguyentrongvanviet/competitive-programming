import math
test = int(input())
for i in range(test) : 
    x = int(input()) 
    delta =  1+8*x  
    b = int(math.sqrt(delta)) 
    if b * b == delta and (-1+b)%2==0:
        print("YES") 
    else : 
        print("NO")  

n , tien = map(int,input().split())
a = list(map(int,input().split())) 
for x in a : 
    tien-=x 
print(n+tien//min(a))
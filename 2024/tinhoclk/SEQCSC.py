n = int(input()) 
a = list(map(int,input().split())) 
for i in range(1,n) : 
    if a[i] - a[i-1] != a[1]-a[0] : 
        print("NO") 
        break; 
else :
    print("YES")

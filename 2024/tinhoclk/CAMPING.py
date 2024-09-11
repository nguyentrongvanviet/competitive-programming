n , X = map(int,input().split())
a = list(map(int,input().split())) 
a.append(X) 
res = 1 
a.sort() 
for i in range(1,len(a),1) : 
    if a[i]!=a[i-1] : res+=1 
    if a[i] ==X : 
        print(res) 
        break
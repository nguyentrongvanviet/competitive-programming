l , r = map(int,input().split())
nt = [0]*int(1e7+1)
prime = list() 
for i in range(2,int(1e7)) : 
    if nt[i] == 0 : 
        nt[i] = i  
        prime.append(i) 
        for j in range(i,int(1e7)//i+1) :
            nt[i*j] = i 
res = 0   
for value in prime : 
    if l<=value and value<=r : 
        res+=1
print(res) 
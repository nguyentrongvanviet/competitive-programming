test = int(input()) 
for _ in range(test) : 
    n ,s = map(int,input().split()) 
    w = list(map(int,input().split())) 
    v = list(map(int,input().split())) 
    res = 0  
    for i in range(n) : 
        if w[i] <=s : res+=v[i]
    print(res) 
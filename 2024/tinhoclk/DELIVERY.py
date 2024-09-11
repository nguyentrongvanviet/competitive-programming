n , k , t = map(int,input().split()) 
time_go= list(map(int,input().split()))
time_get= list(map(int,input().split()))
time_get.insert(0,0) 
time_go.insert(0,0)
time_now = 0  
for i in range(1,n+1) : 
    time_now+=time_go[i] 
    if time_now+k>=time_get[i] : 
        time_now=t+max(time_get[i],time_now)
    else : time_now+=k
print(time_now) 
        
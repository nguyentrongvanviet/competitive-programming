s  = input() 
n = len(s) 
open = 0   
mi=0
for c in s : 
    if c == '(':
        open+=1 
    else :
        open-=1 
    mi = min(mi,open) 

if open == 2 and mi==0:
    pre = [0]*(n+1)   
    suf = [n+5]*(n+1) 
    for i in range(len(s)) : 
        if i!=0 : 
            pre[i] = pre[i-1]
        if s[i] == '(' : 
            pre[i]+=1 
        else : 
            pre[i]-=1 
    for i in range(len(s)-1,-1,-1) : 
        suf[i] = min(suf[i+1],pre[i]) 
    res = 0  
    open = 0   
    for i in range(len(s)) : 
        if s[i] == '(':
            open+=1 
        else : 
            open-=1 
        if open>1 and s[i] == '(' and suf[i+1]>=2:
            res+=1 
    print(res) 
elif open == -2 and mi==-2 :         
    cnt = 0
    open = 0 
    for i in range(len(s)) : 
        if s[i] == ')' : 
            cnt+=1 
            open-=1
        else : 
            open+=1
        if open<0 : 
            break 
    print(cnt) ;  
else : 
    print(0)
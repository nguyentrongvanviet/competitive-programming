s = input() 
n = len(s) 
s+=" "
sum = [0]*(n+1) 
for i in range(n-1,-1,-1) : 
    sum[i] = sum[i+1]  
    if s[i] == ')' and s[i+1]==')' :
        sum[i]+=1
res = 0  
for i in range(n) : 
    if s[i] == '(' and s[i+1] == '(' : 
        res+=sum[i] 
print(res) 
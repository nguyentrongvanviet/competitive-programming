s = input() 
tmp = ""
res = [] 
for x in s : 
    if x.isdigit() : 
        tmp+=x ; 
    elif tmp!="":
        res.append(int(tmp)) 
        tmp=""
if tmp!="" : 
    res.append(int(tmp))
res.sort() 
for i in res : 
    print(i,end=" ") 
    
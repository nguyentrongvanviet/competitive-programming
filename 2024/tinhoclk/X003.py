s = input()
cur = ""
for c in s : 
    if c.isdigit() : cur+=c 
    elif cur !="":
        print(cur,end=" ")
        cur = ""
if cur!="" : print(cur)
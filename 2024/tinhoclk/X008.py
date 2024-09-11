def check(s) : 
    ok1 , ok2 = 0 , 0  
    for x in s : 
        if x.isdigit() : ok1 = 1 
        if x.isalpha() : ok2 = 1 
    return ok1 and ok2 
s = input() 
if s[:3] =="s64" : 
    print("Error!")
elif len(s) < 5  or check(s) == 0 : print("Error!")
else : print(len(s)) 
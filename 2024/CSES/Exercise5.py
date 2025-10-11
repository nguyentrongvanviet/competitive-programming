import numpy as np

arr = np.random.randint(1, 6, size=10)
print(arr) 
for i in range(1,len(arr)) :   
    if arr[i] != arr[i-1] : 
        print("False")  
        break
else : 
    print("True")  
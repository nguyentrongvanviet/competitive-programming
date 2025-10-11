import numpy as np

arr = np.random.randint(-3, 4, size=(1,15))
for i in range(0,len(arr)): 
    for j in range(0,len(arr[i])) : 
        if arr[i][j] == 0 : 
            print(i , j) 
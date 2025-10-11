import numpy as np

arr = np.random.randint(0, 16, size=(1, 20))

for x  in arr :
    for y in x :  
        if 5 < y and y < 10 : 
            print(y)
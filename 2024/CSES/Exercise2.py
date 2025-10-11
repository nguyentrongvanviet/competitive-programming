import numpy as np

random_2d_array = np.random.rand(4,4)
for row in random_2d_array:
    for value in row : 
        if value>0.5 : 
            print(value) 


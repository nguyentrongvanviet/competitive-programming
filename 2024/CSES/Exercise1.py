import numpy as np

# Create a random 3D array with dimensions 3x4x5
random_3d_array = np.random.rand(3, 4, 5)
print(random_3d_array)
second_plane = random_3d_array[0, :, :]
print(second_plane)


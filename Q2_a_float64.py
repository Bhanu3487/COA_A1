import time

# run this code for n = [64, 128, 256, 512, 1024]
n = 1024
print(f"Multiplication of matrices of size ", n , "x" , n , "with elements of datatype float64 and in python")

def identity_matrix(n):
    # Create an n x n identity matrix with float64 elements
    return [[1.0 if i == j else 0.0 for j in range(n)] for i in range(n)]

mat1 = identity_matrix(n)
mat2 = mat1

# Initialize result matrix with zeros of type float64
result = [[0.0 for _ in range(n)] for _ in range(n)]

start_time = time.process_time()

# Perform matrix multiplication
for i in range(n):
    for j in range(n):
        for k in range(n):
            result[i][j] += mat1[i][k] * mat2[k][j]

end_time = time.process_time()

cpu_time_used = end_time - start_time
print(f"CPU Time Used: {cpu_time_used} seconds")

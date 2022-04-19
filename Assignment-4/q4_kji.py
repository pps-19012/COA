from audioop import mul
import random
import time


def mulMat(N):
    rslt = [[0] * N] * N
    mat1 = [[0] * N] * N
    mat2 = [[0] * N] * N

    for i in range(0, N):
        for j in range(0, N):
            mat1[i][j] = random.randint(0, 50)

    for i in range(0, N):
        for j in range(0, N):
            mat2[i][j] = random.randint(0, 50)

    start = time.time()
    for k in range(0, N):
        for j in range(0, N):
            rslt[i][j] = 0

            for i in range(0, N):
                rslt[i][j] += mat1[i][k] * mat2[k][j]
                
    end = time.time()
    programTime = end - start
    return programTime


n = int(input("Enter n(size of matrix): "))
print('{0:1.7f}'.format(mulMat(n)))
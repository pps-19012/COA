import random
import time

def mulMat(n):
    rslt = [[0]*n]*n
    mat1 = [[0]*n]*n
    mat2 = [[0]*n]*n
    serial = 0;
    
    for i in range(0,n):
        for j in range(0,n):
            mat1[i][j] = random.randint(0,32767)
            
    for i in range(0,n):
        for j in range(0,n):
            mat2[i][j] = random.randint(0,32767)
    
    start  = time.time()
    for i in range(0, n):
        for j in range(0,n):
            rslt[i][j] = 0
            
            for k in range(0,n):
                rslt[i][j] += mat1[i][k] * mat2[k][j]
                
            print(serial, " ", rslt[i][j])
            serial += 1 
    end = time.time()
    programTime = end - start
    return programTime

n = int(input("Enter n(size of matrix): "))
print(mulMat(n))

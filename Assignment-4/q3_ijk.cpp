#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define N 128

using namespace std;
 
void multMat(int mat1[][N],
              int mat2[][N],
              int rslt[][N])
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            rslt[i][j] = 0;
            for (k = 0; k < N; k++)
                rslt[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main()
{
    int rslt[N][N];
    int mat1[N][N];
    int mat2[N][N];
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            
            mat1[i][j] = rand()%100;
            mat2[i][j] = rand()%100;
        }
    }

    timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);

    multMat(mat1, mat2, rslt);
    clock_gettime(CLOCK_REALTIME, &end);
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    long double elapsed = seconds + nanoseconds*(long double)1e-9;

    cout<<"\nTime taken by meat portion of the code: "<<elapsed<<" seconds\n";
    return 0;
}
#include <iostream>
#include <random>
#include <stdio.h>
#include <ctime>

using namespace std;

void mulMat(int n, int *mat1, int *mat2) {
    int rslt[n][n];
    int serial = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < n; k++) {
                // rslt[i][j] += mat1[i][k] * mat2[k][j];
                rslt[i][j] += *((mat1+i*n) + k) * (*((mat2+k*n) + j));
            }
 
            cout <<serial<<"  " << rslt[i][j] << endl;
            ++serial;
        }
    }
}
 
int main() {
    timespec start, end;
    int n;
    cout << "Enter n(size of matrix): ";
    cin >> n;
    
    int mat1[n][n], mat2[n][n];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            mat1[i][j] = rand();
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            mat2[i][j] = rand();
        }
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    mulMat(n,(int *)mat1,(int *)mat2);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    double elapsed = seconds + nanoseconds * 1e-9;
    cout << "\nTime taken to multiply the two matrices: " << elapsed << " seconds\n";

    return 0;
}
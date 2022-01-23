#include <iostream>
#include<ctime>
#define N 101
#define BILLION  1000000000.0
using namespace std;

const __int128 initial = -1;
__int128 arr[N];

void init()
{
    for(__int128 i=0; i<N; i++)
        arr[i] = initial;
}

__int128 fibonacciSequence(int n) {
    if(arr[n] == initial) {
        if(n <= 1)
            arr[n] = n;
        else
            arr[n] = fibonacciSequence(n-1) + fibonacciSequence(n-2);
    }
    return arr[n];
}

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 256 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main()
{
    init();
    timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    cout <<fibonacciSequence(100) << endl;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent = (end.tv_sec - start.tv_sec) 
                        + (end.tv_nsec - start.tv_nsec) / BILLION;
    cout<<"\nTime taken: "<<time_spent<<" seconds\n";
    return 0;
}
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
#define BILLION  1000000000.0
#define N 101

const __int128 initial = -1;
__int128 arr[N];

void setup()
{
    for(__int128 i=0; i<N; i++)
        arr[i] = initial;
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
    setup();
    arr[0] = 0, arr[1] = 1, arr[2] = 1;
    int i, n;
    cout << "N : ";
    cin >> n;
    timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (i = 2; i < n+1; ++i)
    {
        arr[i] = arr[i-1] + arr[i-2];
        cout << " " << arr[i] << endl;
    }
    cout <<arr[n] << endl;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent = (end.tv_sec - start.tv_sec) 
                        + (end.tv_nsec - start.tv_nsec) / BILLION;
    cout<<"\nTime taken: "<<time_spent<<" seconds\n";
    return 0;
}
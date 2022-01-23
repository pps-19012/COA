#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
#define BILLION  1000000000.0
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
    __int128 n1 = 0, n2 = 1, n3;
    int i;
    int n;
    cout<<"N: ";
    cin >>n;
    timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (i = 2; i < n + 1; ++i)
    {
        n3 = n1 + n2;
        cout << n3 << endl;
        n1 = n2;
        n2 = n3;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent = (end.tv_sec - start.tv_sec) 
                        + (end.tv_nsec - start.tv_nsec) / BILLION;
    cout<<"\nTime taken: "<<time_spent<<" seconds\n";
    return 0;
}
#include <ctime>
#include <iostream>
#define BILLION  1000000000.0
using namespace std;

std::ostream &
operator<<(std::ostream &dest, __int128 value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __int128 tmp = value < 0 ? -value : value;
        char buffer[256];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 fibonacciSequence(__int128 x)
{
    if ((x == 1) || (x == 0))
    {
       
        return (x);
    }
    else
    {
        
        return (fibonacciSequence(x - 1) + fibonacciSequence(x - 2));
    }
}

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    cout << fibonacciSequence(n) << endl;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent = (end.tv_sec - start.tv_sec) 
                        + (end.tv_nsec - start.tv_nsec) / BILLION;
    cout<<"\nTime taken: "<<time_spent<<" seconds\n";
    return 0;
}
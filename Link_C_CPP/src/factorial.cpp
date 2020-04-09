#include "factorial.hpp"


unsigned long long factorial(int n)
{
    if(n < 0)
        return 0;

    return (n == 1 ? 1 : n * factorial(n - 1));
}
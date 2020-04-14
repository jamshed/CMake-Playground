#include "factorial/factorial.h"


uint64_t factorial(int num)
{
    if(num < 0)
        return 0;

    if(num == 0)
        return 1;

    return num * factorial(num - 1);
}

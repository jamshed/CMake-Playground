#include <cstdio>
#include <cstdlib>

#include "greet.hpp"
#include "factorial.hpp"

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("Invalid arguments. Usage: ./main <NAME> <INTEGER>");
        return 1;
    }

    greet(argv[1]);

    int n = atoi(argv[2]);
    printf("The factorial of %d is %llu\n", n, factorial(n));

    return 0;
}
#include "greeter/greet.hpp"
#include "factorial/factorial.h"

#include <cstdio>
#include <cstdlib>


int main(int argc, char** argv)
{
    if(argc < 3)
    {
        // Move it to some module.
        printf("Usage: main <your_name> <integer>");
        exit(EXIT_FAILURE);
    }

    greet_user(argv[1]);
    printf("The factorial of %s is %lu.\n", argv[2], factorial(atoi(argv[2])));

    return EXIT_SUCCESS;
}
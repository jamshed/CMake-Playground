#include "greeter/greet.hpp"

#include <iostream>


void greet_user(const char *name)
{
    // printf("Hello %s!\n", name);
    std::cout << "Hello " << name << "!\n";
}
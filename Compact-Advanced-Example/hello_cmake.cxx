#include <iostream>
#include <cmath>

#include "Hello_CMake_Config.h"

#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        // Report version of the project
        std::cout << argv[0] << " Version " << Hello_CMake_VERSION_MAJOR << "."
                << Hello_CMake_VERSION_MINOR << "\n";

        std::cout << "Usage: " << argv[0] << " number.\n";
        return 1;
    }


    const double input_val = std::stod(argv[1]);
    
    #ifdef USE_MYMATH
        const double root = my_sqrt(input_val);
    #else
        const double root = sqrt(input_val);
    #endif

    std::cout << "Square_Root (" << input_val << ") = " << root << "\n";

    return 0;
}
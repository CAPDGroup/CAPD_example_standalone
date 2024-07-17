#include <iostream>
#include "capd/capdlib.h"

using namespace capd;

int main()
{
    std::cout.precision(17);

    interval i = interval(1.0) / interval(10.0);

    std::cout << i << '\n';
    return 0;
}

#include "DynamicMath.h"
#include <iostream>

int main()
{
    double x = 11;
    double y = 2;

    std::cout << DynamicMath::add(x, y) << std::endl;
    std::cout << DynamicMath::sub(x, y) << std::endl;
    std::cout << DynamicMath::mul(x, y) << std::endl;
    std::cout << DynamicMath::div(x, y) << std::endl;

    DynamicMath dyn;
    dyn.print();
    return 0;
}

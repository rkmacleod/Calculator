#include "../Calculator.hpp"

#include <iostream>         //std::cout, std::cin
#include <iomanip>          //std::setprecision
#include <vector>           //std::vector, std::vector::push_back

int main()
{
    Calculator c1;
    Calculator c2;

    c1.calculate();
    c1.calculate();
    std::cout << "flag" << std::endl;
    c2.calculate();
    c1.calculate();
}
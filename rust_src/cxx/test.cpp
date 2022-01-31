#include "math_c.hpp"

#include <cassert>
#include <iostream>

int main()
{
    assert(add(1, 2) == 5);
    std::cout << "All tests passed" << std::endl;
}
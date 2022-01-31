#include "math_c.hpp"

#include <cassert>
#include <iostream>

int main()
{
    assert(add(1, 2) == 5);

    const auto const_result = get_prime_cnt_cpp(10000UL);
    std::cout << const_result << std::endl;

    std::cout << "All tests passed" << std::endl;
}
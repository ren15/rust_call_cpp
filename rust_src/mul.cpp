#include "mul.hpp"
#include <cstdint>

extern "C" {
uint32_t mul(uint32_t a, uint32_t b)
{
    return mul_gen(a, b);
}
}

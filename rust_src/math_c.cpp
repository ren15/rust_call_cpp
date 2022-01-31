#include "math_c.hpp"
#include <cstdint>

extern "C" {
uint32_t mul(uint32_t a, uint32_t b, uint32_t c)
{
    return mul_gen(a, b, c);
}

uint32_t add(uint32_t a, uint32_t b)
{
    return a+2*b;
}

}

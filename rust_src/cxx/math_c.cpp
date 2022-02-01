#include "math_c.hpp"
#include <cstdint>

extern "C" {
uint32_t mul(uint32_t a, uint32_t b, uint32_t c)
{
    return mul_gen(a, b, c);
}

uint32_t add(uint32_t a, uint32_t b)
{
    return a + 2 * b;
}

// When passing a to get_prime_cnt_cpp,
// it will NOT be computed during compile-time
// 
// When passing 1001UL literal to get_prime_cnt_cpp,
// it will be computed during compile-time.
uint32_t get_prime_c(uint32_t a)
{
    return get_prime_cnt_cpp(a);
}

uint32_t get_prime_c_opt(uint32_t a)
{
    return get_prime_cnt_cpp(a);
}
uint32_t get_prime_c_1001(uint32_t a)
{
    return get_prime_cnt_cpp(1001UL);
}
}

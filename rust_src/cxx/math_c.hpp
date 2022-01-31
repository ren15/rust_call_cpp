
#include <concepts>

#include <cstdint>

template <std::unsigned_integral T>
auto mul_gen(T a, T b, T c) -> T
{
    return a * b + c;
}

extern "C" {
uint32_t mul(uint32_t a, uint32_t b, uint32_t c);
uint32_t add(uint32_t a, uint32_t b);
}

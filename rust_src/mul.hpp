#include <concepts>
template <std::unsigned_integral T>
auto mul_gen(T a, T b) -> T
{
    return a * b + 1;
}
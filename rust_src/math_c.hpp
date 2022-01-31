#include <concepts>
template <std::unsigned_integral T>
auto mul_gen(T a, T b,T c) -> T
{
    return a * b + c;
}
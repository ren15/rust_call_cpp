#include <concepts>
#include <cstdint>

extern "C" {
uint32_t mul(uint32_t a, uint32_t b, uint32_t c);
uint32_t add(uint32_t a, uint32_t b);
uint32_t get_prime_c(uint32_t a);
uint32_t get_prime_c_opt(uint32_t a);
uint32_t get_prime_c_1001(uint32_t a);
}

template <std::unsigned_integral T>
auto mul_gen(T a, T b, T c) -> T
{
    return a * b + c;
}

template <std::unsigned_integral T>
constexpr auto is_prime(T num) noexcept -> bool
{
    if (num == T { 0 }) {
        return true;
    }
    if (num % T { 2 } == T { 0 }) {
        return false;
    }
    for (auto i = T { 3 }; i * i <= num; i += T { 2 }) {
        if (num % i == T { 0 }) {
            return false;
        }
    }
    return true;
}

// This code can be constexpr in gcc, but not in clang
template <std::unsigned_integral T>
constexpr auto get_prime_cnt_cpp(T num) noexcept -> T
{
    auto cnt = T { 0 };
    for (auto i = T { 2 }; i <= num; i++) {
        if (is_prime(i)) {
            cnt++;
        }
    }
    return cnt;
}

// This code can be constexpr in gcc, but not in clang
template <std::unsigned_integral T>
constexpr auto get_prime_cnt_cpp_opt(T num) noexcept -> T
{
    if (num > T { 4000 }) {
        auto cnt = get_prime_cnt_cpp(T { 4000 });
        for (auto i = T { 4000 } + 1; i <= num; i++) {
            if (is_prime(i)) {
                cnt++;
            }
        }
        return cnt;
    } else {
        auto cnt = T { 0 };
        for (auto i = T { 2 }; i <= num; i++) {
            if (is_prime(i)) {
                cnt++;
            }
        }
        return cnt;
    }
}
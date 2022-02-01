#include "math_c.hpp"

#include <benchmark/benchmark.h>

#include <cstdint>

uint64_t get_num()
{
    static auto num = static_cast<uint64_t>(rand() % 10 + 100);
    return num;
}

static void BM_get_prime_cnt_cpp(benchmark::State& state)
{
    for (auto _ : state) {
        auto a = get_prime_cnt_cpp(1001UL);
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_get_prime_cnt_cpp);

static void BM_get_prime_c(benchmark::State& state)
{
    for (auto _ : state) {
        auto a = get_prime_c(1001UL);
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_get_prime_c);

static void BM_get_prime_c_opt(benchmark::State& state)
{
    for (auto _ : state) {
        auto a = get_prime_c_opt(state.range(0));
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_get_prime_c_opt)->RangeMultiplier(2)->Range(64, 1 << 12);;

static void BM_get_prime_c_1001(benchmark::State& state)
{
    for (auto _ : state) {
        auto a = get_prime_c_1001(1001UL);
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_get_prime_c_1001);

BENCHMARK_MAIN();
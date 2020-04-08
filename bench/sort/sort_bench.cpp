#include <benchmark/benchmark.h>

#include <algorithm>
#include <random>
#include <sort/sort.hpp>
#include <vector>

static void BM_SortVector(benchmark::State& state) {
  std::mt19937 g(200);
  std::vector<int> v(state.range(0));
  std::generate(v.begin(), v.end(), [&g]() { return g(); });

  for (auto _ : state) {
    exercise::sort(v.begin(), v.end(), std::less<int>());
  }
}
BENCHMARK(BM_SortVector)->Range(8, 8 << 20);

static void BM_SortVectorSTL(benchmark::State& state) {
  std::mt19937 g(200);
  std::vector<int> v(state.range(0));
  std::generate(v.begin(), v.end(), [&g]() { return g(); });
  for (auto _ : state) {
    std::sort(v.begin(), v.end(), std::less<int>());
  }
}
BENCHMARK(BM_SortVectorSTL)->Range(8, 8 << 20);

static void BM_SortVectorMerge(benchmark::State& state) {
  std::mt19937 g(200);
  std::vector<int> v(state.range(0));
  std::generate(v.begin(), v.end(), [&g]() { return g(); });
  for (auto _ : state) {
    exercise::sortMerge(v.begin(), v.end(), std::less<int>());
  }
}
BENCHMARK(BM_SortVectorMerge)->Range(8, 8 << 20);

#include <benchmark/benchmark.h>
#include"count.h"
//filename is defined in count.h
static void withMultiread(benchmark::State& state) {
  for (auto _ : state) {
    countWords(fileName, 4, true);
  }
}
// Register the function as a benchmark
BENCHMARK(withMultiread);

// Define another benchmark
static void withoutMultiread(benchmark::State& state) {
  for (auto _ : state) {
    countWords(fileName, 4, false);
  }
}
BENCHMARK(withoutMultiread);

// single threaded
static void singleThreaded(benchmark::State& state) {
  for (auto _ : state) {
    countWords(fileName, 1, false);
  }
}
BENCHMARK(singleThreaded);
BENCHMARK_MAIN();

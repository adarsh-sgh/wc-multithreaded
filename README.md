This project counts number of words in a file using multiple threads
# How to run

1. Change the full path of the file in count.h
2. compile and run main.cpp

# Benchmark

1. setup [google benchmark](https://github.com/google/benchmark)
2. compile, modify if needed and run benchmark.cpp using below command
```bash
g++ Benchmark.cpp -std=c++17 -isystem benchmark/include \
  -Lbenchmark/build/src -lbenchmark -lpthread -o Benchmark
  ``` 
# Results

Here *Multiread* means each thread reads its part itself
in without multiread it just counts words in it's part

Here are two sample benchmarks on my machine
![benchmark](images/image-1.png)

with small input
***
![benchmark](images/image-2.png)

with larger input

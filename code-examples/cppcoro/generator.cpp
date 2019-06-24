#include <cppcoro/generator.hpp>

cppcoro::generator<unsigned long long> fibonacci_gen() {
  std::array arr{0ull, 1ull};
  unsigned long long result=0;

  do {
    co_yield result;
    arr[0] = arr[1];
    arr[1] = result;
    result = arr[0] + arr[1];
  } while (result >= arr[1]);
}
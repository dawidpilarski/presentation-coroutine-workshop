#include <iostream>
#include <array>
#include <cppcoro/generator.hpp>

generator<unsigned long long> fibonacci(){
  std::array arr{0ull, 1ull};
  auto result = 0ull;

  do{
    co_yield result;
    arr[0] = arr[1];
    arr[1] = result;
    result = arr[0] + arr[1];
  } while (result >= arr[1]);

  //implicit co_return;
}
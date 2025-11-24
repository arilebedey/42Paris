#include "iter.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

void printNum(double x) {
  std::cout << std::fixed << std::setprecision(0) << x << "\n\n";
}

int main() {
  std::srand(std::time(NULL));

  const size_t len = 7;
  double arr[len];

  for (size_t i = 0; i < len; ++i) {
    double base = (std::rand() / (double)RAND_MAX);
    double exp = (std::rand() / (double)RAND_MAX) * 308.0;
    arr[i] = std::pow(10.0, exp) * base;
  }

  iter(arr, 7, printNum);

  double arr_const[4] = {42, 21, 7, 10};
  iter(arr_const, 4, printNum);

  return 0;
}

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: expected one argument" << std::endl;
    return 1;
  }

  RPN rpn;
  return rpn.evaluate(argv[1]);
}

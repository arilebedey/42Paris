#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

static void runTest(std::string const &literal) {
  std::cout << "literal: " << literal << std::endl;
  ScalarConverter::convert(literal);
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc == 3 && std::string(argv[1]) == "i") {
    std::string input = argv[2];
    runTest(input);
    return 0;
  }
  if (argc != 1) {
    std::cerr << "usage: ./casts or ./casts i <literal>" << std::endl;
    return 1;
  }

  runTest("13");
  runTest("-nan");
  runTest("-inf");
  runTest("126");
  runTest("-1.6e308");
  runTest("3.4e38");
  runTest("0.0F");

  return 0;
}

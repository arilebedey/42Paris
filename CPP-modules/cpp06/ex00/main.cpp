// main.cpp
#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static void testFloatDoubleOverflow() {
  std::ostringstream fSafe, dSafe, fOverflow, dOverflow;

  fSafe << std::scientific << std::fixed << std::setprecision(0)
        << std::numeric_limits<float>::max();
  dSafe << std::scientific << std::fixed << std::setprecision(0)
        << std::numeric_limits<double>::max();

  std::string fSafeStr = fSafe.str() + "f";
  std::string dSafeStr = dSafe.str();

  std::cout << std::fixed << fSafeStr << std::endl;
  std::cout << std::fixed << dSafeStr << std::endl;

  std::string fOverflowStr = fSafe.str();
  fOverflowStr.insert(fOverflowStr.find('e') + 1, "+10"); // exponent 10x bigger
  fOverflowStr += "f";

  std::string dOverflowStr = dSafe.str();
  dOverflowStr.insert(dOverflowStr.find('e') + 1, "+10"); // exponent 10x bigger

  std::cout << "Testing safe float:\n";
  ScalarConverter::convert(fSafeStr);
  std::cout << std::endl;

  std::cout << "Testing overflow float:\n";
  ScalarConverter::convert(fOverflowStr);
  std::cout << std::endl;

  std::cout << "Testing safe double:\n";
  ScalarConverter::convert(dSafeStr);
  std::cout << std::endl;

  std::cout << "Testing overflow double:\n";
  ScalarConverter::convert(dOverflowStr);
  std::cout << std::endl;

  std::cout << "float max: " << std::scientific
            << std::numeric_limits<float>::max() << std::endl;
  std::cout << "double max: " << std::scientific
            << std::numeric_limits<double>::max() << std::endl;
}

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
  runTest("42");
  runTest("42.f");
  runTest("-nan");
  runTest("-inf");
  runTest("126");
  testFloatDoubleOverflow();

  return 0;
}

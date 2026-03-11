#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cerr << "Argument is expected" << std::endl;
    return 1;
  }

  BitcoinExchange btc;
  btc.loadPrices("data.csv");
  btc.processInput(argv[1]);

  return _returnValue;
}

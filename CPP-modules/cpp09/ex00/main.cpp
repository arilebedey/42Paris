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
  if (btc.returnValue)
    return 1;
  btc.processInput(argv[1]);

  return btc.returnValue;
}

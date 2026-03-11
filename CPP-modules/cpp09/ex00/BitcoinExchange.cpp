#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _prices(other._prices) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    _prices = other._prices;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.size() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  return true;
}

bool BitcoinExchange::isValidValue(const std::string &value,
                                   double &out) const {
  if (value.empty())
    return false;
  std::istringstream iss(value);
  double res;
  iss >> res;
  if (iss.fail() || !iss.eof())
    return false;
  out = res;
  return true;
}

void BitcoinExchange::processInput(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file" << std::endl;
    returnValue = 1;
    return;
  }

  try {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
  } catch (std::error) {
    std::cerr << "Error: could not read file" << std::endl;
    returnValue = 1;
    return;
  }

  file.close();
}

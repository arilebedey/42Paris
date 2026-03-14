#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : returnValue(0) {}

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

bool BitcoinExchange::isValidValue(const std::string &value, float &out) const {
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

void BitcoinExchange::loadPrices(const std::string &csvFile) {
  std::ifstream file(csvFile.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: could not open database file." << std::endl;
    returnValue = 1;
    return;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string date, priceStr;
    if (!std::getline(iss, date, ',') || !std::getline(iss, priceStr))
      continue;
    float price = std::stof(priceStr);
    _prices[date] = price;
  }
  file.close();
}

void BitcoinExchange::processInput(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file" << std::endl;
    returnValue = 1;
    return;
  }

  std::string line;
  int pass = 1;
  while (std::getline(file, line)) {
    if ((line == "date | value") && pass == 1) {
      continue;
    }
    pass++;

    int spaceCount = std::count(line.begin(), line.end(), ' ');
    if (spaceCount != 2) {
      std::cerr << "Error: too many spaces => " << line << std::endl;
      continue;
    }

    std::istringstream iss(line);
    std::string date, pipe, valueStr;
    iss >> date >> pipe >>
        valueStr; // >> extracts whitespace-delimited tokens from the stream

    if (!isValidDate(date)) {
      std::cerr << "Error: invalid date => " << line << std::endl;
      continue;
    }

    if (pipe != "|") {
      std::cerr << "Error: bad delimiter => " << line << std::endl;
      continue;
    }

    float value;
    if (!isValidValue(valueStr, value)) {
      std::cerr << "Error: bad value => " << line << std::endl;
      continue;
    }

    if (value < 0) {
      std::cerr << "Error: number is not positive " << std::endl;
      continue;
    }

    if (value > 1000) {
      std::cerr << "Error: number is too large" << std::endl;
      continue;
    }

    std::map<std::string, float>::iterator it = _prices.lower_bound(date);
    if (it == _prices.end() || it->first != date) {
      if (it == _prices.begin()) {
        std::cerr << "Error: date too early => " << line << std::endl;
        continue;
      }
      it--;
    }

    std::cout << date << " => " << value << " = " << value * it->second
              << std::endl;
  }

  file.close();
}

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> _prices;

public:
  int returnValue;

  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  bool isValidDate(const std::string &date) const;
  bool isValidValue(const std::string &value, float &out) const;

  void loadPrices(const std::string &csvFile);
  void processInput(const std::string &filename);
};

#endif

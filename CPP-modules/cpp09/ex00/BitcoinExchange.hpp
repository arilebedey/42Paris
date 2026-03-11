#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> _prices;

public:
  int returnValue;

  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  bool isValidDate(const std::string &date);
  bool isValidNum(const std::string &num, double &out);

  void processInput(std::string filename);
  void loadPrices(std::string csvFile);
  double getPrice();
};

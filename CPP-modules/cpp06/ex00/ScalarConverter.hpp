#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
  static void convert(std::string const &literal);

private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &src);
  ScalarConverter &operator=(ScalarConverter const &rhs);
  ~ScalarConverter();
};

#endif

#include "ScalarConverter.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

static bool isCharLiteral(std::string const &s) {
  return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isIntLiteral(std::string const &s) {
  char *end;
  std::strtol(s.c_str(), &end, 10);
  return *end == '\0';
}

static bool isFloatLiteral(std::string const &s) {
  if (s == "+inff" || s == "-inff" || s == "nanf")
    return true;
  char *end;
  std::strtof(s.c_str(), &end);
  return (*end == 'f' || *end == 'F') && *(end + 1) == '\0';
}

static bool isDoubleLiteral(std::string const &s) {
  if (s == "+inf" || s == "-inf" || s == "nan")
    return true;
  char *end;
  std::strtod(s.c_str(), &end);
  return *end == '\0';
}

void ScalarConverter::convert(std::string const &literal) {
  std::cout << std::fixed << std::setprecision(1);

  if (isCharLiteral(literal)) {
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
    return;
  }

  if (isIntLiteral(literal)) {
    long num = std::strtol(literal.c_str(), NULL, 10);
    bool intImpossible = num < std::numeric_limits<int>::min() ||
                         num > std::numeric_limits<int>::max();

    if (intImpossible) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
      std::cout << "double: " << static_cast<double>(num) << std::endl;
      return;
    }

    if (num < 0 || num > 127)
      std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(num)))
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
    return;
  }

  if (isFloatLiteral(literal)) {
    if (literal == "-inff" || literal == "+inff") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << (literal[0] == '+' ? "+inff" : "-inff")
                << std::endl;
      std::cout << "double: " << (literal[0] == '+' ? "+inf" : "-inf")
                << std::endl;
      return;
    }

    std::string numericPart = literal.substr(0, literal.size() - 1);
    double dInput = std::strtod(numericPart.c_str(), NULL);

    if (std::isinf(dInput)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
      return;
    }

    if (std::isnan(dInput)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: nanf" << std::endl;
      std::cout << "double: nan" << std::endl;
      return;
    }

    if (dInput < -std::numeric_limits<float>::max() ||
        dInput > std::numeric_limits<float>::max()) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
      return;
    }

    float f = std::strtof(literal.c_str(), NULL);
    double d = static_cast<double>(f);

    if (f < 0 || f > 127)
      std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(f)))
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (f < std::numeric_limits<int>::min() ||
        f > static_cast<float>(std::numeric_limits<int>::max()))
      std::cout << "int: impossible" << std::endl;
    else
      std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    return;
  }

  if (isDoubleLiteral(literal)) {
    double d = std::strtod(literal.c_str(), NULL);

    if (std::isnan(d)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: nanf" << std::endl;
      std::cout << "double: nan" << std::endl;
      return;
    }

    if (std::isinf(d)) {
      if (literal != "+inf" && literal != "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
      }
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
      std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
      return;
    }

    if (d < 0 || d > 127)
      std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max())
      std::cout << "int: impossible" << std::endl;
    else
      std::cout << "int: " << static_cast<int>(d) << std::endl;

    float f = static_cast<float>(d);
    if (std::isinf(f))
      std::cout << "float: impossible" << std::endl;
    else
      std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
    return;
  }

  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

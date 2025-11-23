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
  return *end == 'f' && *(end + 1) == '\0';
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
    long integer = std::strtol(literal.c_str(), NULL, 10);
    bool intImpossible = integer < std::numeric_limits<int>::min() ||
                         integer > std::numeric_limits<int>::max();

    if (intImpossible) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << static_cast<float>(integer) << "f" << std::endl;
      std::cout << "double: " << static_cast<double>(integer) << std::endl;
      return;
    }

    if (integer < 0 || integer > 127)
      std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(integer)))
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
    std::cout << "int: " << integer << std::endl;
    std::cout << "float: " << static_cast<float>(integer) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(integer) << std::endl;
    return;
  }

  if (isFloatLiteral(literal)) {
    float f = std::strtof(literal.c_str(), NULL);
    double d = static_cast<double>(f);

    if (std::isnan(f)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: nanf" << std::endl;
      std::cout << "double: nan" << std::endl;
      return;
    }
    if (std::isinf(f)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
      std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
      return;
    }

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

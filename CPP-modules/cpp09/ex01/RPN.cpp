#include "RPN.hpp"
#include <cmath>
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other)
    _stack = other._stack;
  return *this;
}

bool RPN::isOperator(const std::string &token) const {
  return token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                               token[0] == '*' || token[0] == '/');
}

bool RPN::isNumber(const std::string &token) const {
  if (token.empty())
    return false;
  if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
    return true;
  return false;
}

double RPN::applyOperator(char op, double left, double right) const {
  double result;
  switch (op) {
  case '+':
    result = left + right;
    break;
  case '-':
    result = left - right;
    break;
  case '*':
    result = left * right;
    break;
  case '/':
    result = left / right;
    break;
  default:
    return 0;
  }
  if (std::isinf(result) || std::isnan(result))
    throw std::overflow_error("overflow");
  return result;
}

int RPN::evaluate(const std::string &expression) {
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {
    if (isNumber(token)) {
      _stack.push(token[0] - '0');
    } else if (isOperator(token)) {
      if (_stack.size() < 2) {
        std::cerr << "Error: too many operators or not enough numbers"
                  << std::endl;
        return 1;
      }
      double right = _stack.top();
      _stack.pop();
      double left = _stack.top();
      _stack.pop();
      if (token[0] == '/' && right == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        return 1;
      }
      try {
        _stack.push(applyOperator(token[0], left, right));
      } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
      }
    } else {
      std::cerr << "Error: invalid character" << std::endl;
      return 1;
    }
  }

  if (_stack.size() != 1) {
    std::cerr << "Error: not enough operators or too many numbers" << std::endl;
    return 1;
  }

  std::cout << _stack.top() << std::endl;
  return 0;
}

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN {
private:
  std::stack<double, std::list<double> > _stack;

  bool isOperator(const std::string &token) const;
  bool isNumber(const std::string &token) const;
  double applyOperator(char op, double left, double right) const;

public:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  int evaluate(const std::string &expression);
};

#endif

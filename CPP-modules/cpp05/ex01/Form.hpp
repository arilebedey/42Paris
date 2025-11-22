#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
private:
  const std::string _name;
  const int _toSign;
  const int _toExecute;
  bool _isSigned;

public:
  Form(void);
  Form(const std::string &name, int tosign, int toexec);
  Form(const Form &src);
  ~Form(void);

  Form &operator=(const Form &src);
  const std::string &getName(void) const;
  int getToSign(void) const;
  int getToExec(void) const;
  bool getIsSigned(void) const;

  class GradeToHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high"; }
  };
  class GradeToLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low"; }
  };

  void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif

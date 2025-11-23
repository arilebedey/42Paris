#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm {
private:
  const std::string _name;
  const int _toSign;
  const int _toExecute;
  bool _isSigned;

public:
  AForm(void);
  AForm(const std::string &name, int toSign, int toExec);
  AForm(const AForm &src);
  virtual ~AForm(void);

  AForm &operator=(const AForm &src);
  const std::string &getName(void) const;
  int getToSign(void) const;
  int getToExec(void) const;
  bool getIsSigned(void) const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low"; }
  };

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
  void checkSignedAndExecutable(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &Form);

#endif

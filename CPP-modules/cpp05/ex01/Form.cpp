#include "Form.hpp"

Form::Form(void)
    : _name("defaultname"), _toSign(1), _toExecute(1), _isSigned(false) {}

Form::Form(const std::string &name, int toSign, int toExec)
    : _name(name), _toSign(toSign), _toExecute(toExec), _isSigned(false) {
  if (toSign < 1 || toExec < 1)
    throw GradeToHighException();
  else if (toSign > 150 || toExec > 150)
    throw GradeToLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _toSign(src._toSign), _toExecute(src._toExecute),
      _isSigned(src._isSigned) {}

Form::~Form() {}

Form &Form::operator=(const Form &src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

const std::string &Form::getName(void) const { return _name; }

int Form::getToSign(void) const { return _toSign; }

int Form::getToExec(void) const { return _toExecute; }

bool Form::getIsSigned(void) const { return _isSigned; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _toSign)
    throw GradeToLowException();
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << f.getName() << " Form is :\n"
      << (f.getIsSigned() ? " - signed" : " - not signed")
      << "\n - requires grade " << f.getToSign()
      << " to sign \n - requires grade " << f.getToExec() << " to execute";
  return out;
}

#include "AForm.hpp"

AForm::AForm(void)
    : _name("default"), _toSign(1), _toExecute(1), _isSigned(false) {}

AForm::AForm(const std::string &name, int toSign, int toExec)
    : _name(name), _toSign(toSign), _toExecute(toExec), _isSigned(false) {
  if (toSign < 1 || toExec < 1)
    throw GradeTooHighException();
  else if (toSign > 150 || toExec > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _toSign(src._toSign), _toExecute(src._toExecute),
      _isSigned(src._isSigned) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

const std::string &AForm::getName(void) const { return _name; }

int AForm::getToSign(void) const { return _toSign; }

int AForm::getToExec(void) const { return _toExecute; }

bool AForm::getIsSigned(void) const { return _isSigned; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _toSign)
    throw GradeTooLowException();
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << f.getName() << " AForm is :\n"
      << (f.getIsSigned() ? " - signed" : " - not signed")
      << "\n - requires grade " << f.getToSign()
      << " to sign \n - requires grade " << f.getToExec() << " to execute";
  return out;
}

void AForm::checkSignedAndExecutable(const Bureaucrat &executor) const {
  if (!_isSigned)
    throw std::runtime_error("Form is not signed");
  if (executor.getGrade() > _toExecute)
    throw GradeTooLowException();
}

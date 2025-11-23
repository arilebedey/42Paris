#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  if (this != &src) {
    AForm::operator=(src);
    _target = src._target;
  }
  return *this;
}

const std::string &PresidentialPardonForm::getTarget(void) const {
  return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  checkSignedAndExecutable(executor);
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblerox"
            << std::endl;
}

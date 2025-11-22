#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("defaultarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  if (this != &src) {
    AForm::operator=(src);
    _target = src._target;
  }
  return *this;
}

const std::string &RobotomyRequestForm::getTarget(void) const {
  return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  checkSignedAndExecutable(executor);
  std::cout << "* intense drilling *" << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << getTarget() << " has been robotized" << std::endl;
  else
    std::cout << "The robotomy failed" << std::endl;
}

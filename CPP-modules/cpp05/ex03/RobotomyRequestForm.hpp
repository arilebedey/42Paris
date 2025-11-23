#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  ~RobotomyRequestForm(void);

  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
  const std::string &getTarget(void) const;
  void execute(const Bureaucrat &executor) const;
};

#endif

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &src);
  ~PresidentialPardonForm(void);

  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
  const std::string &getTarget(void) const;
  void execute(const Bureaucrat &executor) const;
};

#endif

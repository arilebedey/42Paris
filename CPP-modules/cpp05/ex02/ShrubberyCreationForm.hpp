#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
  const std::string &getTarget(void) const;
  void execute(const Bureaucrat &executor) const;
};

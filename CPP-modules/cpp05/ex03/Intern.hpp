#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern(void);
  Intern(const Intern &src);
  ~Intern(void);
  Intern &operator=(const Intern &src);

  AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
  AForm *createShrubbery(const std::string &target) const;
  AForm *createRobotomy(const std::string &target) const;
  AForm *createPresidential(const std::string &target) const;
};

#endif

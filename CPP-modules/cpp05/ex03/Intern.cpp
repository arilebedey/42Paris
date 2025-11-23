#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &src) { (void)src; }

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &src) {
  (void)src;
  return *this;
}

AForm *Intern::createShrubbery(const std::string &target) const {
  std::cout << "Intern creates shrubbery creation" << std::endl;
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const {
  std::cout << "Intern creates robotomy request" << std::endl;
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const {
  std::cout << "Intern creates presidential pardon" << std::endl;
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};
  AForm *(Intern::*formCreators[3])(const std::string &target)
      const = {&Intern::createShrubbery, &Intern::createRobotomy,
               &Intern::createPresidential};

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i])
      return (this->*formCreators[i])(target);
  }

  std::cout << "Intern couldn’t create form. Unknown form name: " << formName
            << std::endl;
  return NULL;
}

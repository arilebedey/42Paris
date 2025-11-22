#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  if (this != &src)
    this->_grade = src.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string &Bureaucrat::getName(void) const { return _name; }

int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << "Bureaucrat's " << bureaucrat.getName() << " grade is "
      << bureaucrat.getGrade();
  return out;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " couldn’t sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " couldn’t execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

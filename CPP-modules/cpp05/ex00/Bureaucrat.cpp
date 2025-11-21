#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("defaultname"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
  if (grade < 1)
    throw GradeToHighException();
  else if (grade > 150)
    throw GradeToLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  if (this != &src)
    this->_grade = src.getGrade();
  return *this;
}

const std::string &Bureaucrat::getName(void) const { return _name; }

int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
  if (_grade - 1 < 1)
    throw GradeToHighException();
  _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (_grade + 1 > 150)
    throw GradeToLowException();
  _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << "Bureaucrat's " << bureaucrat.getName() << " grade is "
      << bureaucrat.getGrade();
  return out;
}

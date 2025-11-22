#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(const Bureaucrat &src);
  ~Bureaucrat();

  const std::string &getName(void) const;
  int getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);

  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "The grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "The grade is too low"; }
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

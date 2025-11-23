#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  std::srand(time(NULL));

  try {
    Intern intern;
    AForm *form;

    form = intern.makeForm("shrubbery creation", "forest");
    delete form;

    form = intern.makeForm("presidential pardon", "high pardon");
    delete form;

    form = intern.makeForm("unicorn creation", "?");
    delete form;

    form = intern.makeForm("robotomy request", "robotomy");
    Bureaucrat reboot("I reboot?", 45);
    std::cout << "\n----- Sign and execute form with Bureaucrat robotomy "
                 "(randomness) -----"
              << std::endl;
    reboot.signForm(*form);
    std::cout << "\n";
    for (int i = 0; i < 5; ++i) {
      reboot.executeForm(*form);
      std::cout << "\n";
    }
    delete form;

  } catch (const std::exception &e) {
    std::cerr << "Unexpected exception: " << e.what() << std::endl;
  }

  return 0;
}

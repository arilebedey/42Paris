#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

int main() {
  std::srand(time(NULL));

  try {
    Bureaucrat powerfulLady("Alice", 1);
    Bureaucrat reboot("I reboot?", 45);
    Bureaucrat mickaeljackson("Mickael", 140);

    ShrubberyCreationForm cerfa("feuillage");
    RobotomyRequestForm abcd1234("Marvin");
    PresidentialPardonForm desole("Le voisin de Mickael");

    std::cout << "\n----- Signing -----" << std::endl;
    mickaeljackson.signForm(cerfa);
    reboot.signForm(abcd1234);
    reboot.signForm(desole);
    powerfulLady.signForm(desole);

    std::cout << "\n----- Form Robotomy (randomness) -----" << std::endl;
    for (int i = 0; i < 5; ++i)
      reboot.executeForm(abcd1234);

    std::cout << "\n----- Execution -----" << std::endl;
    mickaeljackson.executeForm(abcd1234);
    mickaeljackson.executeForm(cerfa);
    powerfulLady.executeForm(desole);
    powerfulLady.executeForm(cerfa);

  } catch (const std::exception &e) {
    std::cerr << "Unexpected exception: " << e.what() << std::endl;
  }

  return 0;
}

#include "../includes/phonebook.hpp"
#include <iostream>
#include <sstream>

static void search_func(Phonebook phonebook) {
  std::string input;
  int number;
  phonebook.displaycontacts();
  if (!phonebook.getcount())
    return;
  while (1) {
    std::cout << "Enter the index of the contact you want to display: ";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(1);
    }
    std::istringstream iss(input);
    if (iss >> number && iss.eof()) {
      if (number > phonebook.getcount() || number > 8 || number < 1) {
        std::cout << "Please enter a correct index." << std::endl;
        continue;
      }
      phonebook.displayonecontact(number);
      break;
    } else {
      std::cout << "Please enter a number." << std::endl;
    }
  }
}

int main(void) {
  Phonebook phonebook;
  std::string input;
  while (1) {
    std::cout << "Enter your command (ADD, SEARCH or EXIT):" << std::endl;
    std::cout << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(1);
    } else if (input == "ADD")
      phonebook.addcontact();
    else if (input == "SEARCH")
      search_func(phonebook);
    else if (input == "EXIT")
      break;
  }
  std::cout << "Phonebook destroyed! Exited." << std::endl;
  return (0);
}

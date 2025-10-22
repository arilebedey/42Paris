#include <iostream>
#include <string>

int main(void) {
  std::string brain = "HI THIS IS BRAIN";

  std::string *stringPTR = &brain;
  std::string &stringREF = brain;

  std::cout << "Memory address of brain     : " << &brain << std::endl;
  std::cout << "Memory address of stringPTR : " << stringPTR << std::endl;
  std::cout << "Memory address of stringREF : " << &stringREF << std::endl;
  std::cout << std::endl;
  std::cout << "Value of brain     : " << brain << std::endl;
  std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
  std::cout << "Value of stringREF : " << stringREF << std::endl;
  return (0);
}

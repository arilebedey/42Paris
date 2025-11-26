#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  std::vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  const std::vector<int> const_v = v2;

  try {
    std::vector<int>::iterator i = easyfind(v, 20);
    std::cout << "Found: " << *i << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::vector<int>::const_iterator i = easyfind(v2, 10);
    std::cout << "Found: " << *i << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

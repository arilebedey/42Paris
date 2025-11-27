#include <iostream>
#include <numeric>

#include "MutantStack.hpp"

int main() {
  try {

    MutantStack<int> mutantstack;

    mutantstack.push(5);
    mutantstack.push(17);
    std::cout << "Pushed 5, 17" << std::endl;

    std::cout << "Top element: " << mutantstack.top() << std::endl;

    mutantstack.pop();
    std::cout << "Top element after pop: " << mutantstack.top() << std::endl;

    mutantstack.push(737);
    std::cout << "Pushed 737" << std::endl;

    std::cout << "Exploring stack contents with iterator: ";
    for (MutantStack<int>::iterator it = mutantstack.begin();
         it != mutantstack.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    int sum = std::accumulate(mutantstack.begin(), mutantstack.end(), 0);
    std::cout << "Sum of all elements using iterators (accumulate): " << sum
              << std::endl;

    std::cout << "Is stack empty? " << (mutantstack.empty() ? "Yes" : "No")
              << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 0;
  }
  return 0;
}

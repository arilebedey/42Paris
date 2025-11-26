#include "Array.hpp"
#include <iostream>

int main() {
  // int
  Array<int> intArray(5);
  for (size_t i = 0; i < intArray.size(); i++)
    intArray[i] = i * 10;

  std::cout << "intArray: ";
  for (size_t i = 0; i < intArray.size(); i++)
    std::cout << intArray[i] << " ";
  std::cout << std::endl;

  // copy constructor
  Array<int> copyArray(intArray);
  std::cout << "Original intArray[1]: " << intArray[1]
            << ", copyArray[1]: " << copyArray[1] << std::endl;

  // double + heap alloc
  Array<double> *dblArrPtr = new Array<double>(4);
  for (size_t i = 0; i < dblArrPtr->size(); i++)
    (*dblArrPtr)[i] = 0.5 * (i + 1);

  std::cout << "dblArray (heap): ";
  for (size_t i = 0; i < dblArrPtr->size(); i++)
    std::cout << (*dblArrPtr)[i] << " ";
  std::cout << std::endl;

  delete dblArrPtr;

  // out-of-range
  try {
    std::cout << intArray[10] << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}

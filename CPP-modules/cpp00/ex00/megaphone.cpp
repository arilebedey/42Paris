#include <iostream>

int main(int argc, char **argv) {
  int i;
  int j;

  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  j = 1;
  while (argc > 1 && argv && argv[j]) {
    i = 0;
    while (argv[j][i]) {
      std::cout << (char)std::toupper(argv[j][i]);
      i++;
    }
    j++;
  }
  std::cout << std::endl;
  return (0);
}

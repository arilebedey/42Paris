#include "Harl.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
  {
		std::cout << "usage: harlFilter FILTER_LEVEL" << std::endl;
		std::cout << "available levels: DEBUG, INFO, WARNING and ERROR" << std::endl;
    return (1);
  }

	Harl harl;

	harl.filter(av[1]);

	return 0;
}

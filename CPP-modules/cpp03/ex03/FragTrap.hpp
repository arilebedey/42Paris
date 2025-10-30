#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &src);
  FragTrap &operator=(const FragTrap &other);
  ~FragTrap();

  void highFivesGuys();
};

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &src);
  ~ScavTrap();

  ScavTrap &operator=(const ScavTrap &other);

  void guardGate();
};

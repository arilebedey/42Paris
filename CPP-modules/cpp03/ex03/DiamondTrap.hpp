#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &src);
  DiamondTrap &operator=(const DiamondTrap &other);
  ~DiamondTrap();

  void whoAmI();
  using ScavTrap::attack;
};

#endif

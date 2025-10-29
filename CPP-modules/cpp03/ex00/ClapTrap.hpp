#include <string>

class ClapTrap {
private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

public:
  ClapTrap();
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &src);
  ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

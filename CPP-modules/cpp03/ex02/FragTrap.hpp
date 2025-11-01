#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &src);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &other);

  void highFivesGuys(void);
};

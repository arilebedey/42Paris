#include <string>

class Animal {
public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  ~Animal();

  virtual void makeSound() const;
  std::string getType() const;

protected:
  std::string type;
};

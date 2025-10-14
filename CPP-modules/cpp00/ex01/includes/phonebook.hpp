#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
private:
  Contact _contacts[8];
  int _insert_count;

public:
  Phonebook();
  Phonebook(const Phonebook &other);
  Phonebook &operator=(const Phonebook &other);
  ~Phonebook();

  void addcontact();
  void displaycontacts() const;
  void displayonecontact(int index) const;
  int getcount() const;
};

#endif

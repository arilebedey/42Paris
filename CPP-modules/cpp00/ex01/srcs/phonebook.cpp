#include "../includes/phonebook.hpp"
#include <iomanip>
#include <iostream>

static std::string troncate_string(const std::string str) {
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");
  return (str);
}

Phonebook::Phonebook() { _insert_count = 0; }

Phonebook::Phonebook(const Phonebook &other) { *this = other; }

Phonebook &Phonebook::operator=(const Phonebook &other) {
  if (this != &other) {
    _insert_count = other._insert_count;
    for (int i = 0; i < 8; i++)
      _contacts[i] = other._contacts[i];
  }
  return *this;
}

Phonebook::~Phonebook() {}

void Phonebook::displaycontacts() const {
  if (!_insert_count) {
    std::cout << "Please add a contact before searching for contacts."
              << std::endl;
    return;
  }
  std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
  int count = (_insert_count < 8) ? _insert_count : 8;
  for (int i = 0; i < count; i++) {
    std::cout << "|" << std::setw(10) << std::right << i + 1 << "|"
              << std::setw(10) << std::right
              << troncate_string(_contacts[i].getfirstname()) << "|"
              << std::setw(10) << std::right
              << troncate_string(_contacts[i].getlastname()) << "|"
              << std::setw(10) << std::right
              << troncate_string(_contacts[i].getnickname()) << "|"
              << std::endl;
  }
}

void Phonebook::addcontact() {
  std::string input;
  Contact new_contact;

  while (1) {
    std::cout << "Enter First name" << std::endl << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(0);
    }
    if (!input.empty()) {
      new_contact.setfirstname(input);
      break;
    }
  }

  while (1) {
    std::cout << "Enter Last name" << std::endl << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(0);
    }
    if (!input.empty()) {
      new_contact.setlastname(input);
      break;
    }
  }

  while (1) {
    std::cout << "Enter Nickname" << std::endl << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(0);
    }
    if (!input.empty()) {
      new_contact.setnickname(input);
      break;
    }
  }

  while (1) {
    std::cout << "Enter Phone Number" << std::endl << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(0);
    }
    if (!input.empty()) {
      new_contact.setphonenumber(input);
      break;
    }
  }

  while (1) {
    std::cout << "Enter Darkest secret" << std::endl << ">";
    if (!std::getline(std::cin, input)) {
      std::cout << "EOF detected. Phonebook destroyed! Exited." << std::endl;
      exit(0);
    }
    if (!input.empty()) {
      new_contact.setdarkestsecret(input);
      break;
    }
  }
  _contacts[_insert_count % 8] = new_contact;
  _insert_count++;
}

void Phonebook::displayonecontact(int index) const {
  std::cout << "First name: " << _contacts[index - 1].getfirstname()
            << std::endl;
  std::cout << "Last name: " << _contacts[index - 1].getlastname() << std::endl;
  std::cout << "Nickname: " << _contacts[index - 1].getnickname() << std::endl;
  std::cout << "Phone Number: " << _contacts[index - 1].getphonenumber()
            << std::endl;
  std::cout << "Darkest secret: " << _contacts[index - 1].getdarkestsecret()
            << std::endl;
}

int Phonebook::getcount() const { return (_insert_count); }

#include "../includes/contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const Contact &other) { *this = other; }

Contact &Contact::operator=(const Contact &other) {
  if (this != &other) {
    _firstname = other._firstname;
    _lastname = other._lastname;
    _nickname = other._nickname;
    _darkestsecret = other._darkestsecret;
    _phonenumber = other._phonenumber;
  }
  return *this;
}

void Contact::setfirstname(const std::string &firstname) {
  _firstname = firstname;
}

void Contact::setlastname(const std::string &lastname) { _lastname = lastname; }

void Contact::setnickname(const std::string &nickname) { _nickname = nickname; }

void Contact::setdarkestsecret(const std::string &darkestsecret) {
  _darkestsecret = darkestsecret;
}

void Contact::setphonenumber(const std::string &phonenumber) {
  _phonenumber = phonenumber;
}

std::string Contact::getfirstname() const { return (_firstname); }

std::string Contact::getlastname() const { return (_lastname); }

std::string Contact::getnickname() const { return (_nickname); }

std::string Contact::getdarkestsecret() const { return (_darkestsecret); }

std::string Contact::getphonenumber() const { return (_phonenumber); }

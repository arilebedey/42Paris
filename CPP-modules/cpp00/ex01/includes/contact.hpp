#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <string>

class Contact {
private:
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _darkestsecret;
  std::string _phonenumber;

public:
  Contact();
  Contact(const Contact &other);
  Contact &operator=(const Contact &other);
  ~Contact();

  void setfirstname(const std::string &firstname);
  void setlastname(const std::string &lastname);
  void setnickname(const std::string &nickname);
  void setdarkestsecret(const std::string &darkestsecret);
  void setphonenumber(const std::string &phonenumber);

  std::string getfirstname() const;
  std::string getlastname() const;
  std::string getnickname() const;
  std::string getdarkestsecret() const;
  std::string getphonenumber() const;
};

#endif

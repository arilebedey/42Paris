#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <ostream>
#include <vector>

class bigint {
private:
  std::vector<int> d;

public:
  bigint();
  ~bigint();
  bigint(unsigned long long);
  bigint(const bigint &other);

  bigint &operator+=(const bigint &o);
  bigint operator+(const bigint &o) const;
  bigint &operator=(const bigint &o);

  bigint &operator++();
  bigint operator++(int);

  bigint &operator<<=(const unsigned int s);
  bigint operator<<(const unsigned int s) const;

  bigint &operator>>=(const bigint &b);

  bool operator>(const bigint &b) const;
  bool operator<(const bigint &b) const;

  bool operator==(const bigint &o) const;
  bool operator!=(const bigint &o) const;

  bool operator<=(const bigint &o) const;
  bool operator>=(const bigint &o) const;

  void print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &bi);

#endif

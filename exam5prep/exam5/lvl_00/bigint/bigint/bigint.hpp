#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class bigint {
private:
  std::vector<int> digits;

public:
  bigint();
  ~bigint();
  bigint(unsigned long long);
  bigint(const bigint &other);

  bigint operator+(const bigint &other) const;
  bigint &operator=(const bigint &other);
  bigint &operator+=(const bigint &other);

  bigint &operator++();
  bigint operator++(int);

  bigint &operator<<=(unsigned int s);
  bigint &operator>>=(const bigint &s);

  bigint operator<<(unsigned int s) const;
  bigint operator>>(unsigned int s) const;

  bool operator<(const bigint &other) const;
  bool operator>(const bigint &other) const;

  bool operator==(const bigint &other) const;
  bool operator!=(const bigint &other) const;

  bool operator<=(const bigint &other) const;
  bool operator>=(const bigint &other) const;

  void print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &bi);
#endif

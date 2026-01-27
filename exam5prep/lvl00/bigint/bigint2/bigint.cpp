#include "bigint.hpp"

bigint::bigint() { d.push_back(0); };

bigint::bigint(const bigint &other) : d(other.d) {};

bigint::~bigint() {};

bigint::bigint(unsigned long long n) {
  if (n == 0) {
    d.push_back(0);
    return;
  }

  while (n > 0) {
    d.push_back(n % 10);
    n /= 10;
  }
};

void bigint::print(std::ostream &os) const {
  if (d.empty()) {
    os << "0";
    return;
  }

  for (int i = d.size() - 1; i >= 0; i--)
    os << d[i];
}

std::ostream &operator<<(std::ostream &os, const bigint &bi) {
  bi.print(os);
  return os;
}

bigint &bigint::operator+=(const bigint &o) {
  size_t ms = std::max(d.size(), o.d.size());
  d.resize(ms);

  int carry = 0;
  for (size_t i = 0; i < d.size(); i++) {
    int b = i < o.d.size() ? o.d[i] : 0;
    int sum = d[i] + b + carry;
    d[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry == 1)
    d.push_back(1);

  return *this;
};

bigint bigint::operator+(const bigint &o) const {
  bigint res = *this;
  res += o;
  return res;
}

bigint &bigint::operator++() {
  bigint o(1);
  (*this) += o;
  return *this;
}

bigint bigint::operator++(int) {
  bigint n = *this;
  ++(*this);
  return n;
}

bigint &bigint::operator<<=(const unsigned int s) {
  if (s == 0 || (d.size() == 1 && d[0] == 0)) {
    return *this;
  }

  d.insert(d.begin(), s, 0);

  return *this;
}

bigint bigint::operator<<(const unsigned int s) const {
  bigint n = *this;
  n <<= s;
  return n;
}

bigint &bigint::operator>>=(const bigint &b) {
  unsigned long long n = 0;
  for (size_t i = 0; i < b.d.size(); i++)
    n = n * 10 + b.d[i];

  if (n == 0)
    return *this;

  if (n >= d.size()) {
    d.clear();
    d.push_back(0);
    return *this;
  }

  d.erase(d.begin(), d.begin() + n);
  return *this;
}

bool bigint::operator>(const bigint &o) const {
  if (o.d.size() != d.size())
    return d.size() > o.d.size();

  for (size_t i = d.size(); i-- > 0;) {
    if (o.d[i] != d[i])
      return d[i] > o.d[i];
  }
  return false;
}

// bigint &bigint::operator=(const bigint &other) {}
;

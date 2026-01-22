#include "bigint.hpp"

bigint::bigint() { digits.push_back(0); };
bigint::~bigint() {};

bigint::bigint(unsigned long long n) {
  if (n == 0) {
    digits.push_back(0);
    return;
  }

  while (n > 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
}

bigint::bigint(const bigint &other) : digits(other.digits) {}

bigint &bigint::operator=(const bigint &other) {
  if (&other != this)
    digits = other.digits;
  return *this;
}

bigint &bigint::operator+=(const bigint &other) {
  size_t max_size = std::max(digits.size(), other.digits.size());
  digits.resize(max_size);

  int carry = 0;
  for (size_t i = 0; i < max_size; ++i) {
    int b = i < other.digits.size() ? other.digits[i] : 0;
    int sum = digits[i] + b + carry;
    digits[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry == 1)
    digits.push_back(1);

  return *this;
}

bigint bigint::operator+(const bigint &other) const {
  bigint res = *this;
  res += other;
  return res;
}

bigint &bigint::operator++() {
  bigint t(1);
  *this += t;
  return *this;
}

bigint bigint::operator++(int) {
  bigint t = *this;
  ++(*this);
  return t;
}

bigint &bigint::operator<<=(unsigned int s) {
  if (s == 0 || (digits.size() == 1 && digits[0] == 0))
    return *this;

  digits.insert(digits.begin(), s, 0);
  return *this;
}

bigint &bigint::operator>>=(const bigint &s) {
  unsigned int n = 0;
  for (size_t i = 0; i < s.digits.size(); ++i)
    n = n * 10 + s.digits[s.digits.size() - 1 - i];

  if (n == 0)
    return *this;

  if (n >= digits.size()) {
    digits.clear();
    digits.push_back(0);
    return *this;
  }

  digits.erase(digits.begin(), digits.begin() + n);
  return *this;
}

bigint bigint::operator<<(unsigned int s) const {
  bigint res = *this;
  res <<= s;
  return res;
}

bigint bigint::operator>>(unsigned int s) const {
  bigint res = *this;
  res >>= bigint(s);
  return res;
}

bool bigint::operator<(const bigint &other) const {
  if (digits.size() != other.digits.size())
    return (digits.size() < other.digits.size());

  for (size_t i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] != other.digits[i])
      return (digits[i] < other.digits[i]);
  }

  return false;
}

bool bigint::operator>(const bigint &other) const { return other < *this; };

bool bigint::operator==(const bigint &other) const {
  return digits == other.digits;
};

bool bigint::operator!=(const bigint &other) const {
  return digits != other.digits;
};

bool bigint::operator<=(const bigint &other) const {
  return (digits == other.digits || (*this) < other);
};

bool bigint::operator>=(const bigint &other) const {
  return (digits == other.digits || *this > other);
};

std::ostream &operator<<(std::ostream &os, const bigint &bi) {
  if (bi.digits.empty()) {
    os << "0";
    return os;
  }

  for (int i = bi.digits.size() - 1; i >= 0; --i) {
    os << bi.digits[i];
  }
  return os;
}

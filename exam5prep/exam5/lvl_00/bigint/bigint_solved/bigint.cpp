#include "bigint.hpp"
#include <algorithm>

bigint::bigint() {}
bigint::~bigint() {}

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
  if (this != &other)
    digits = other.digits;
  return *this;
}

bigint bigint::operator+(const bigint &other) const {
  bigint result = *this;
  result += other;
  return result;
}

bigint &bigint::operator+=(const bigint &other) {
  size_t max_size = std::max(digits.size(), other.digits.size());
  digits.resize(max_size, 0);

  int carry = 0;
  for (size_t i = 0; i < max_size; ++i) {
    int a = i < digits.size() ? digits[i] : 0;
    int b = i < other.digits.size() ? other.digits[i] : 0;

    int sum = a + b + carry;
    digits[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry > 0)
    digits.push_back(carry);

  return *this;
}

bigint &bigint::operator++() {
  *this += bigint(1);
  return *this;
}

bigint bigint::operator++(int) {
  bigint temp = *this;
  ++(*this);
  return temp;
}

bigint bigint::operator<<(unsigned int shift) const {
  if (shift == 0 || (digits.size() == 1 && digits[0] == 0))
    return bigint(*this);

  bigint result = *this;
  result <<= shift;
  return result;
}

bigint &bigint::operator<<=(unsigned int shift) {
  if (shift == 0 || (digits.size() == 1 && digits[0] == 0))
    return *this;

  digits.insert(digits.begin(), shift, 0);
  return *this;
}

bigint bigint::operator>>(unsigned int shift) const {
  if (shift == 0)
    return *this;

  bigint result = *this;
  result >>= bigint(shift);
  return result;
}

bigint &bigint::operator>>=(const bigint &shift) {
  unsigned int s = 0;
  for (size_t i = 0; i < shift.digits.size(); ++i)
    s = s * 10 + shift.digits[shift.digits.size() - 1 - i];

  if (s == 0)
    return *this;

  if (s >= digits.size()) {
    digits.clear();
    digits.push_back(0);
    return *this;
  }

  digits.erase(digits.begin(), digits.begin() + s);
  return *this;
}

bool bigint::operator<(const bigint &other) const {
  if (digits.size() != other.digits.size())
    return digits.size() < other.digits.size();

  for (int i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] != other.digits[i])
      return digits[i] < other.digits[i];
  }

  return false;
}

bool bigint::operator>(const bigint &other) const { return other < *this; }

bool bigint::operator==(const bigint &other) const {
  return digits == other.digits;
}

bool bigint::operator!=(const bigint &other) const { return !(*this == other); }

bool bigint::operator<=(const bigint &other) const { return !(other < *this); }

bool bigint::operator>=(const bigint &other) const { return !(*this < other); }

std::ostream &operator<<(std::ostream &os, const bigint &bi) {
  if (bi.digits.empty()) {
    os << "0";
    return os;
  }

  for (int i = bi.digits.size() - 1; i >= 0; --i)
    os << bi.digits[i];

  return os;
}

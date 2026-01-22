#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <vector>

class bigint
{
    private:
        std::vector<int> digits;

    public:
        bigint();
        ~bigint();
        bigint(unsigned long long n);
        bigint(const bigint& other);

        bigint& operator=(const bigint& other);
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bigint operator++(int);
        bigint& operator++();

        bigint operator<<(unsigned int shift) const;
        bigint operator>>(unsigned int shift) const;
        bigint& operator<<=(unsigned int shift);
        bigint& operator>>=(const bigint& shift);

        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;

        friend std::ostream& operator<<(std::ostream& os, const bigint& bi); //0
};

#endif // BIGINT_HPP

#pragma once
#include <iostream>

class Fixed
{
    public:
        Fixed();

        ~Fixed();

        Fixed(const Fixed &f1);

        Fixed& operator = (const Fixed &f1);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
    int                 number;
    static const int    fractional_bits = 8;
};
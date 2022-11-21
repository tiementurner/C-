#pragma once
#include <iostream>
#include <cmath>


class Fixed
{
    public:
        Fixed();

        Fixed(const int num);

        ~Fixed();

        Fixed(const Fixed &f1);

        Fixed& operator = (const Fixed &f1);

        Fixed(float const val);

        float toFloat(void) const;

        int toInt(void) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    
    private:
        int                 number;
        static const int    fractional_bits = 8;
};

std::ostream& operator << (std::ostream& o, const Fixed &f1);


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
        Fixed(float const val);
        Fixed& operator = (const Fixed &f1);
        
        float toFloat(void) const;
        int toInt(void) const;
        
        int                    getRawBits(void) const;
        void                   setRawBits(int const raw);
        static Fixed&          min(Fixed &a, Fixed &b);
        static const Fixed&    min(const Fixed &a, const Fixed &b);
        static Fixed&          max(Fixed &a, Fixed &b);
        static const Fixed&    max(const Fixed &a, const Fixed &b);
        

        bool operator > (const Fixed &f1);
        bool operator < (const Fixed &f1);
        bool operator >= (const Fixed &f1);
        bool operator <= (const Fixed &f1);
        bool operator == (const Fixed &f1);
        bool operator != (const Fixed &f1);

        Fixed operator+(const Fixed &f1);
        Fixed operator-(const Fixed &f1);
        Fixed operator*(const Fixed &f1);
        Fixed operator/(const Fixed &f1);

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        

    private:
        int                 number;
        static const int    fractional_bits = 8;
};

std::ostream& operator << (std::ostream& o, const Fixed &f1);


#include "Fixed.hpp"

Fixed::Fixed() : 
                number(0)
{
}
Fixed::Fixed(const int num)
{
    this->number = (num << this->fractional_bits);
}

Fixed::Fixed(float const val)
{
    this->number = int(roundf(val * (1 << this->fractional_bits)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &f1) 
{
    *this = f1;
}

Fixed& Fixed::operator=(const Fixed &f1)
{
    this->number = f1.getRawBits();
    return *this;
}

//comparison operators:

bool Fixed::operator>(const Fixed &f1)
{
    return this->number > f1.number;
}

bool Fixed::operator<(const Fixed &f1)
{
    return this->number < f1.number;
}

bool Fixed::operator>=(const Fixed &f1)
{
    return this->number >= f1.number;
}

bool Fixed::operator<=(const Fixed &f1)
{
    return this->number <= f1.number;
}

bool Fixed::operator==(const Fixed &f1)
{
    return this->number == f1.number;
}

bool Fixed::operator!=(const Fixed &f1)
{
    return this->number != f1.number;
}

//arithmetic operators

Fixed Fixed::operator+(const Fixed &f1)
{
    Fixed result;

    result.setRawBits(this->number + f1.number);
    return (result);
}

Fixed Fixed::operator-(const Fixed &f1)
{
    Fixed result;

    result.setRawBits(this->number - f1.number);
    return (result);
}

Fixed Fixed::operator*(const Fixed &f1)
{
    float result;
    result = this->toFloat() * f1.toFloat();
    Fixed temp(result);
    return (temp);
}

Fixed Fixed::operator/(const Fixed &f1)
{
    float result;
    result = this->toFloat() / f1.toFloat();
    Fixed temp(result);
    return (temp);
}

//Increment operators

Fixed& Fixed::operator++()
{
    ++this->number;
    return(*this);
}

Fixed& Fixed::operator--()
{
    --this->number;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed result = *this;
    ++*this;
    return(result);
}

Fixed Fixed::operator--(int)
{
    Fixed result = *this;
    --*this;
    return(result);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    Fixed a2(a);
    Fixed b2(b);
    if (a2 > b2)
        return (b);
    return (a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    Fixed a2(a);
    Fixed b2(b);
    if (a2 > b2)
        return (a);
    return (b);
}


int Fixed::getRawBits(void) const
{
    return (this->number);
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

float Fixed::toFloat(void) const
{
    return float(this->number) / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->number >> fractional_bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed &f1)
{
    o << f1.toFloat();
    return o;
}
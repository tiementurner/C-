#include "Fixed.hpp"

Fixed::Fixed() : 
                number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = (num << fractional_bits);
}

Fixed::Fixed(float const val)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = int(roundf(val * (1 << fractional_bits)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f1) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f1;
}

Fixed& Fixed::operator=(const Fixed &f1)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->number = f1.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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
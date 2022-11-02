#include "Fixed.hpp"

Fixed::Fixed() : 
                number(0)
{
    std::cout << "Default constructor called" << std::endl;
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
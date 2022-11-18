#include "Fixed.hpp"
#include <iostream>
int main( void ) {
    Fixed a;

    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    Fixed c(10.23f);
    std::cout << "actual stored value of 10.23f = " << c.getRawBits() << std::endl;
    std::cout << "represented as float = " << c.toFloat() << std::endl;
    Fixed test(1);
    int i = 1;
    std::cout << i++ << std::endl;
    std::cout << ++i << std::endl;
    std::cout << test++ << std::endl;
    std::cout << ++test << std::endl;

    a = 13.23f;
    b = 127;
    std::cout << "a : " << a << " || b : " << b << std::endl;
    std::cout << "b / a : " << (b / a) << std::endl;
    std::cout << "b * a : " << (b * a) << std::endl;
    std::cout << "b + a : " << (b + a) << std::endl;
    std::cout << "b - a : " << (b - a) << std::endl;

    return 0;
}
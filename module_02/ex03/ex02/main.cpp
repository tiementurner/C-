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
    std::cout << "post decrement 1(int) = " << i-- << std::endl;
    std::cout << "pre decrement 1(int) = " <<  --i << std::endl;
    std::cout << "post decrement 1(Fixed) = " <<  test-- << std::endl;
    std::cout << "pre decrement 1(Fixed) = " << --test << std::endl;

    a = 2;
    b = 4;
    std::cout << "a : " << a << " || b : " << b << std::endl;
    std::cout << "b / a : " << (b / a) << std::endl;
    std::cout << "b * a : " << (b * a) << std::endl;
    std::cout << "b + a : " << (b + a) << std::endl;
    std::cout << "b - a : " << (b - a) << std::endl;

    if (a > b)
        std::cout << "a is groter" << std::endl;
    if (a < b)
        std::cout << "b is groter" << std::endl;
    if (a == b)
        std::cout << "a gelijk aan b" << std::endl;
    if (a != b)
        std::cout << "a is niet b" << std::endl;
    if (a <= b)
        std::cout << "a is kleiner of gelijk aan b" << std::endl;
    if (a >= b)
        std::cout << "a groter of gelijk b" << std::endl;

    std::cout << (2 << 31) << std::endl;
    return 0;
}
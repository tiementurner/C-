#include "whatever.hpp"
#include <iostream>
int main( void ) {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( b, a ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( b, a ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    float e = 12.05;
    float f = 12.05;

    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

    a = 2;
    b = 2;
    std::cout << &b << std::endl;
    std::cout << &::max(a, b) << std::endl;
    std::cout << &b << std::endl;
    std::cout << &::min(a, b) << std::endl;
    return 0;
}
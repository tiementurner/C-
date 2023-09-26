#include "iter.hpp"
#include <iostream>

void write_if_uneven(int &number)
{
    if (number % 2 == 1)
        std::cout << number << std::endl;
}

void write_char(char &c)
{
    std::cout << c << std::endl;
}

template <typename T>
void write(T &to_write)
{
    std::cout << to_write << std::endl;
}

int main( void ) 
{
    std::string array_one[3] = {"een", "twee", "drie"};
    int         array_two[7] = {1, 2 ,3, 4, 5, 6, 7};
    char        array_three[5] = {'a', 'b', 'c', 'd', 'e'};

    iter(array_one, 3, write);
    iter(array_two, 7, write);
    iter(array_three, 5, write);

    std::cout << std::endl;

    iter(array_two, 7, write_if_uneven);
    iter(array_three, 5, write_char);
    return 0;
}
#include "Array.hpp"



int main()
{
    Array<int>          integer_array(4);
    Array<std::string>  string_array(4);

    string_array[2] = "hoi";
    std::cout << string_array[2];
    integer_array[2] = 3;
    for(int i = 0; i < 4 ; i++)
        std::cout << integer_array[i];

}
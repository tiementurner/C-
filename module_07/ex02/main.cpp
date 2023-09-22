#include "Array.hpp"

void run()
{
    Array<int>          empty_int_array;

    std::cout << "size of empty array: " << empty_int_array.size() << std::endl;

    Array<int>          integer_array(4);
    Array<std::string>  string_array(4);

    std::cout << "size of empty array: " << integer_array.size() << std::endl;
    std::cout << "size of empty array: " << string_array.size() << std::endl;

    string_array[2] = "hoi";
	std::cout << string_array[2] << std::endl;
    try{std::cout << string_array[5];}
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << integer_array[3] << std::endl;

    try{integer_array[-1]= 0;}
	catch(const std::exception &e){std::cout << e.what() << std::endl;}
    
	integer_array[0] = 1;
    integer_array[1] = 2;
    integer_array[2] = 3;
    integer_array[3] = 4;
    for(int i = 0; i < 4 ; i++)
        std::cout << integer_array[i];
    std::cout << std::endl;

    Array<long>         long_array(1);
    
    long_array[0] = 123456789123;
    std::cout << long_array[0] << std::endl;
    
    Array<long>         other_long_array(long_array);
    other_long_array[0] = 0;

    std::cout << long_array[0] << std::endl;
    std::cout << other_long_array[0] << std::endl;
}

int main()
{
    run();
    //while(1);
}
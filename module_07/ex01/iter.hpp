#pragma once
#include <iostream>
template <typename T, std::size_t N> 
void iter(T(&arr)[N], size_t length, void (*function)(T&))
{
    for (std::size_t i = 0; i < length; i++)
        function(arr[i]);
}

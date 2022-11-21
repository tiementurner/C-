#pragma once
#include <iostream>
template <typename T> 
void iter(T *arr, size_t length, void (*function)(T&))
{
    for (std::size_t i = 0; i < length/sizeof(arr[0]); i++)
        function(arr[i]);
}

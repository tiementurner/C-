#pragma once
#include <iostream>
template <typename T> void iter(T *arr, std::size_t length, void (*f)(const T&))
{
    for (std::size_t i = 0; i < length; i++;)
        f(arr[i]);
}
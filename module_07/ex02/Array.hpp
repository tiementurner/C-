#pragma once
#include <cstddef>
#include <iostream>

template <class T> 
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();

        T& operator[](size_t);
    
    private:
        size_t  size;
        T       *ptr;
};
#include "Array.tpp"
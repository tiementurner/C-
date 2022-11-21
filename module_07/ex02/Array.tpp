//#include "Array.hpp"

#pragma once
// #include <cstddef>
// #include <iostream>

template <typename T>
Array<T>::Array() :
                    size(0)
{
    this->ptr = new T[0];
}

template <typename T>
Array<T>::~Array()
{
    delete []ptr;
}

template <typename T>
Array<T>::Array(unsigned int n) 
{
    this->size = sizeof(T) * n;
    this->ptr = new T[size]();
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index > size)
    {
        throw std::exception();
    }
    return (this->ptr[index * sizeof(T)]);
}

//template class Array<int>;
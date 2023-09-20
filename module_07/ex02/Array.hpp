#pragma once
#include <cstddef>
#include <iostream>
#include <exception>

template <class T> 
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();

        size_t size() const;

        T& operator[](std::size_t);
        const T& operator[](std::size_t) const;

        class IndexOutOfBoundsException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return("Index out of bounds!");
                }
        };

    private:
        T           *ptr;
        std::size_t  number_of_elements;
};

#include "Array.tpp"

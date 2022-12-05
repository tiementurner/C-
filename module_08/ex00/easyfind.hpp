#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
void print_seq_container(const T &container)
{
    typename T::const_iterator it;
    std::cout << "Sequence container : | ";
    for(it = begin(container); it != end(container); ++it)
        std::cout << *it << " | ";
    std::cout << std::endl;
}

template <typename T>
typename T::iterator easyfind(T &container, int number)
{
    typename T::iterator ptr;
    ptr = std::find(container.begin(), container.end(), number);
    if (container.end() == ptr)
        throw(std::invalid_argument("No occurence found!"));
    return (ptr);
}
#include "Span.hpp"

Span::Span() : maximum(0)
{
}

Span::Span(unsigned int n) : maximum(n)
{
    std::vector<int> temp;
    storage = temp;
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->maximum = other.maximum;
        this->storage = other.storage;
    }
    return (*this);
}

Span::~Span()
{
}

void    Span::addNumber(int n)
{
    storage.push_back(n);
}

void    Span::print()
{
    std::vector<int>::iterator i;
    std::cout << "Span(max size = " << maximum << "): | ";
    for(i = begin(storage); i != end(storage); ++i)
        std::cout << *i << " | ";
    std::cout << '\n';
}
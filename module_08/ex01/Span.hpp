#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
public:
    typedef std::vector<int>::iterator Iterator;
    Span();
    ~Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int n);
    void addRange(Iterator start, Iterator end);

    void print();

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;




private:
    unsigned int        maximum;
    unsigned int        filled;
    std::vector<int>    storage;
    static int                 max(int x, int y);
    static int                 min(int x, int y);
};


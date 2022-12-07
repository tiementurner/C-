#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
    Span();
    ~Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int n);
    void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

    void print();

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
private:
    unsigned int        maximum;
    unsigned int        filled;
    std::vector<int>    storage;
};


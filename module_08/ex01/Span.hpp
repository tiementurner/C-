#pragma once
#include <vector>
#include <iostream>

class Span
{
public:
    Span();
    ~Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int n);

    void print();

private:
    unsigned int        maximum;
    std::vector<int>    storage;
};


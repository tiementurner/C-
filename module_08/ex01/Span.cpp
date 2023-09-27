#include "Span.hpp"

Span::Span() : maximum(0),
               filled(0)
{
}

Span::Span(unsigned int n) : maximum(n),
                             filled(0)
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
        maximum = other.maximum;
        storage = other.storage;
        filled = other.filled;
    }
    return (*this);
}

Span::~Span()
{
}

void    Span::addNumber(int n)
{
    if (filled == maximum)
        throw(std::length_error("addNumber err: Span is at maximum size!"));
    storage.push_back(n);
    filled++;
}

void    Span::print()
{
    std::vector<int>::iterator i;
    std::cout << "Span(max size = " << maximum << "): | ";
    for(i = begin(storage); i != end(storage); ++i)
        std::cout << *i << " | ";
    std::cout << '\n';
}

unsigned int Span::shortestSpan() const
{
    std::vector<int> temp(storage);
    unsigned int diff = 0;
    unsigned int tmp = 0;

    if (storage.size() <= 1)
        throw(std::range_error("shortestSpan err: Not enough numbers stored."));
    
    std::vector<int>::iterator i;
    std::vector<int>::iterator next;

	std::sort(begin(temp), end(temp));

	diff = *begin(temp) - *std::next(begin(temp), 1);
    for(i = begin(temp); i != end(temp); ++i)
    {
        next = std::next(i, 1);
        if (next == end(temp))
            break;
        tmp = *next - *i;
        if (diff > tmp)
            diff = tmp;
    }
    return (diff);
}

unsigned int Span::longestSpan() const
{
    std::vector<int> temp(storage);
    unsigned int diff = 0;

	if (storage.size() <= 1)
    	throw(std::range_error("longestSpan err: Not enough numbers stored."));
	
	diff = *std::max_element(begin(temp), end(temp))-*std::min_element(begin(temp), end(temp));
    return (diff);

}

void Span::addRange(Iterator start, Iterator end) {
	unsigned int temp_size = storage.size();
    if (filled + std::distance(start, end) > this->maximum) {
		throw std::range_error("addRange err: Range too big for span.");
	}
	storage.insert(storage.end(), start, end);
    filled += (unsigned int)storage.size() -  temp_size;
}

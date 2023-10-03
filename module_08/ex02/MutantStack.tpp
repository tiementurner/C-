#pragma once

template <typename T, class Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
{
    *this = other;
}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &other)
{
	std::deque<int>::iterator it;
    if (this != &other)
	{
        this->c = other.c;
	}
	return (*this);
}

template <typename T, class Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, class Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

#pragma once

template <typename T, class Container>
MutantStack<T, Container>::MutantStack()
{
    this->storage = std::stack<T, Container>();
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
    if (this != &other)
        this->storage = other.storage;
    return (*this);
}



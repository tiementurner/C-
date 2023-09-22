#pragma once
#include <stack>
#include <vector>
#include <iostream>


template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T>
{

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);


        typedef typename Container::iterator iterator;

        iterator    begin(){return std::stack<T>::c.begin();};
        iterator    end(){return std::stack<T>::c.end();};

    private:
        std::stack<T, Container> storage;
};

#include "MutantStack.tpp"


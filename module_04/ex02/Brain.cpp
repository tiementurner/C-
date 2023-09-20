#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "brain constructor" << std::endl;
}

Brain::~Brain()
{
    std::cout << "brain destructor" << std::endl;
}

Brain::Brain(const Brain & other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
        *this->ideas = *other.ideas;
    return (*this);
}

void Brain::get_ideas_adress()
{
    std::cout << "Brain adress: " << static_cast<void*>(ideas) << std::endl;
}
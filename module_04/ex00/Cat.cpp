#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat &c)
{
	*this = c;

	std::cout << "copycat" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "catsound" << std::endl;
}
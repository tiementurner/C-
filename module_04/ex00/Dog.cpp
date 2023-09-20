#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog &c)
{
	*this = c;

	std::cout << "copyDog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "dogsound" << std::endl;
}
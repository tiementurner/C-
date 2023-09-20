#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	this->dog_brain = new Brain();
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog()
{
	delete this->dog_brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog &c)
{
	this->dog_brain = NULL;
	*this = c;
	this->type = "dog copy";
	std::cout << "copyDog" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		if (this->dog_brain)
			delete this->dog_brain;
		this->dog_brain = new Brain(*other.dog_brain);
	}
	std::cout << "dog operator assignment" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}

void Dog::get_ideas_adress()
{
	this->dog_brain->get_ideas_adress();
}
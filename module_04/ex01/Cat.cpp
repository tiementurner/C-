#include "Cat.hpp"
#include <iostream>


Cat::Cat()
{
	this->type = "Cat";
	this->cat_brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat()
{
	delete this->cat_brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat &c)
{
	this->cat_brain = NULL;
	*this = c;
	this->type = "Deep Cat copy";
	std::cout << "copyCat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		if (this->cat_brain)
			delete this->cat_brain;
		this->cat_brain = new Brain(*other.cat_brain);
	}
	std::cout << "Cat operator assignment" << std::endl;
	return (*this);
}


void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

void Cat::get_ideas_adress()
{
	this->cat_brain->get_ideas_adress();
}
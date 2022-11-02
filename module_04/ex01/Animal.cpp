#include "Animal.hpp"

Animal::Animal() : type("beest")
{
	std::cout << "animal constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "animal destructor" << std::endl;
}

Animal::Animal(const Animal& a) {
	*this = a;

	std::cout << "animal copy" << std::endl;
}

Animal& Animal::operator=(const Animal &a)
{
	this->type = a.type;
	std::cout << "animal assignment" << std::endl;
	return *this;
}

std::string Animal::get_type() const
{
	return(this->type);
}

void Animal::makeSound() const
{
	std::cout << "animalsound" << std::endl;
}